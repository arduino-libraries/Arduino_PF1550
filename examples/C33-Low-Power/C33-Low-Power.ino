#include "RTC.h"
#include "r_lpm.h"
#include "PF1550.h"
#include "Wire.h"

class PF1550_Io_C33 : public interface::PF1550_Io
{
  public:

    PF1550_Io_C33(uint8_t const i2c_addr = interface::PF1550_I2C_DEFAULT_ADDR) : _i2c_addr(i2c_addr) {}
    virtual ~PF1550_Io_C33() { }

    void turnOffMCURail() {
      clrBit(Register::PMIC_SW1_CTRL, 0);
      //clrBit(Register::PMIC_SW3_CTRL, 0);
    }

    virtual int begin() {
      Wire3.begin();
      Wire3.setClock(100000);
      uint8_t data[2] = { 0x9C, (1 << 7) };
      writeRegister(PF1550_I2C_ADDR, data, 2, false);
      data[0] = 0x9E;
      data[1] = (1 << 5);
      writeRegister(PF1550_I2C_ADDR, data, 2, false);

      return 1;
    }

    virtual void debug(Stream& stream) {
      _debug = &stream;
    }

    virtual void readRegister(Register const reg_addr, uint8_t *data) {
      uint8_t i2c_data[2];

      i2c_data[0] = (uint8_t)reg_addr;

      writeRegister(PF1550_I2C_ADDR, i2c_data, 1, 1);

      uint8_t retVal = Wire3.requestFrom(PF1550_I2C_ADDR, 1, true);

      if (_debug) {
        _debug->print("requestFrom: ");
        _debug->println(retVal);
      }

      int i = 0;
      while (Wire3.available() && i < 1) {
        data[0] = Wire3.read();
        i++;
      }

      if (_debug) {
        _debug->println("Read:");
        for (i = 0; i < 1; i++) {
          _debug->println(data[i], HEX);
        }
      }
    }

    virtual void writeRegister(uint8_t slave_addr, uint8_t *data, uint8_t data_len, uint8_t restart) {
      if (_debug) {
        _debug->print("Restart: ");
        _debug->println(restart);
        if (!restart) {
          _debug->print("PF1550_Io_EnvieH747::writeRegister at address=");
          _debug->print(data[0], HEX);
          _debug->print(" data=");
          _debug->println(data[1], HEX);
          _debug->print("i2c slave address: ");
          _debug->println(slave_addr);
        } else {
          _debug->print("PF1550_Io_EnvieH747::Read from register at address=");
          _debug->println(data[0], HEX);
        }
      }

      Wire3.beginTransmission(slave_addr);
      Wire3.write(data, data_len);
      uint8_t retVal = Wire3.endTransmission(restart == 0 ? true : false);

      if (_debug) {
        _debug->print("End transmission: ");
        _debug->println(retVal);
      }
      /*
        if (_debug) {
        _debug->println("Write:");
        for (int i = 0; i < data_len; i++) {
          _debug->println(data[i], HEX);
        }
        }
      */
    }
    virtual void setSTANDBY() {}
    virtual void clrSTANDBY() {}

  private:

    uint8_t const _i2c_addr;
    Stream* _debug;
};

static PF1550_Io_C33 io;
PF1550 myPMIC(io);

const int LED_ON_INTERRUPT  = LED_BUILTIN;

void periodic_cbk() {
  static bool clb_st = false;
  if (clb_st) {
    //digitalWrite(LED_ON_INTERRUPT, HIGH);
  }
  else {
    //digitalWrite(LED_ON_INTERRUPT, LOW);
  }
  clb_st = !clb_st;

  Serial.println("PERIODIC INTERRUPT");
}

void alarm_cbk() {
  Serial.println("ALARM INTERRUPT");
  digitalWrite(LED_ON_INTERRUPT, LOW);
  delay(500);
  digitalWrite(LED_ON_INTERRUPT, HIGH);
}

lpm_instance_ctrl_t p_api_ctrl;
lpm_cfg_t p_cfg;

void setup() {
  Serial.begin(9600);

  myPMIC.debug(Serial);
  myPMIC.begin();
  myPMIC.configLDO1(Ldo1Voltage::V_3_30, false, false, false);
  myPMIC.configLDO2(Ldo2Voltage::V_3_30, false, false, false);
  myPMIC.configLDO3(Ldo3Voltage::V_1_20, false, false, false);
  myPMIC.configSw2(Sw2Voltage::V_3_30, Sw2Voltage::V_3_30, Sw2Voltage::V_3_30, Sw2CurrentLimit::I_1_5_A, false, false, false);

  //io.turnOffMCURail();

  p_cfg.low_power_mode = LPM_MODE_DEEP; //  LPM_MODE_SLEEP  LPM_MODE_STANDBY    LPM_MODE_STANDBY_SNOOZE    LPM_MODE_DEEP
  p_cfg.standby_wake_sources = LPM_STANDBY_WAKE_SOURCE_IRQ0 | LPM_STANDBY_WAKE_SOURCE_RTCALM;
  p_cfg.dtc_state_in_snooze = LPM_SNOOZE_DTC_DISABLE; // LPM_SNOOZE_DTC_ENABLE LPM_SNOOZE_DTC_DISABLE
  p_cfg.power_supply_state = LPM_POWER_SUPPLY_DEEPCUT0; // LPM_POWER_SUPPLY_DEEPCUT0, LPM_POWER_SUPPLY_DEEPCUT1, LPM_POWER_SUPPLY_DEEPCUT3
  p_cfg.output_port_enable = LPM_OUTPUT_PORT_ENABLE_RETAIN; // LPM_OUTPUT_PORT_ENABLE_RETAIN LPM_OUTPUT_PORT_ENABLE_HIGH_IMPEDANCE
  p_cfg.io_port_state = LPM_IO_PORT_NO_CHANGE;  // LPM_IO_PORT_NO_CHANGE LPM_IO_PORT_RESET
  p_cfg.deep_standby_cancel_source = LPM_DEEP_STANDBY_CANCEL_SOURCE_RTC_ALARM;

  R_LPM_Open(&p_api_ctrl, &p_cfg);

  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_ON_INTERRUPT, OUTPUT);
  digitalWrite(LED_ON_INTERRUPT, HIGH);

  pinMode(LEDR, OUTPUT);
  digitalWrite(LEDR, LOW);
  delay(200);
  digitalWrite(LEDR, HIGH);

  RTC.begin();
  RTCTime mytime(1, Month::JANUARY, 2000, 12, 10, 00, DayOfWeek::TUESDAY, SaveLight::SAVING_TIME_ACTIVE);

  if (!RTC.isRunning()) {
    RTC.setTime(mytime);
  }

  RTCTime alarmtime;
  alarmtime.setSecond(35);

  AlarmMatch am;
  am.addMatchSecond();

  if (!RTC.setPeriodicCallback(periodic_cbk, Period::ONCE_EVERY_2_SEC)) {
    Serial.println("ERROR: periodic callback not set");
  }

  if (!RTC.setAlarmCallback(alarm_cbk, alarmtime, am)) {
    Serial.println("ERROR: alarm callback not set");
  }

}

void loop() {
  static bool status = false;

  R_LPM_LowPowerModeEnter(&p_api_ctrl);

  RTCTime currenttime;
  if (status) {

    if (RTC.isRunning()) {
      Serial.println("RTC is running");
    }
    else {
      Serial.println("RTC is not running");
    }

    /* GET CURRENT TIME FROM RTC */
    RTC.getTime(currenttime);

    /* PRINT CURRENT TIME on Serial */
    Serial.print("Current time: ");
    /* DATE */
    Serial.print(currenttime.getDayOfMonth());
    Serial.print("/");
    Serial.print(Month2int(currenttime.getMonth()));
    Serial.print("/");
    Serial.print(currenttime.getYear());
    Serial.print(" - ");
    Serial.print(currenttime.getUnixTime());
    Serial.print(" - ");

    struct timeval tv;
    gettimeofday(&tv, NULL);
    Serial.print(tv.tv_sec);
    Serial.print(" - ");

    /* ORE:MINUTI:SECONDI */
    Serial.print(currenttime.getHour());
    Serial.print(":");
    Serial.print(currenttime.getMinutes());
    Serial.print(":");
    Serial.println(currenttime.getSeconds());

    //digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    //digitalWrite(LED_BUILTIN, LOW);
  }

  status = !status;
  delay(1000);
}
