#include <Arduino.h>
#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"
#include "FS.h"
#include "SPIFFS.h"

void setup()
{
  //https://ht-deko.com/arduino/esp-wroom-32.html#23
  //https://github.com/espressif/arduino-esp32/tree/master/libraries/SPIFFS
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("");

  SPIFFS.begin(true);

/* CREATE FILE */
#if 0
  File fp = SPIFFS.open("/TEST.TXT", FILE_WRITE); // 書き込み、存在すれば上書き
  char buf[BUF_SIZE + 1];
  String s = "The quick brown fox jumps over the lazy dog.\r\n";
  s.toCharArray(buf, BUF_SIZE);
  for (int i = 0; i < 20; i++)
    fp.write((uint8_t *)buf, BUF_SIZE);
  fp.close();

  /* READ FILE */
  fp = SPIFFS.open("/TEST.TXT", FILE_READ); // 読み取り
  while (fp.read((uint8_t *)buf, BUF_SIZE) == BUF_SIZE)
    Serial.print(buf);
  fp.close();

  /* DELETE FILE */
  //SPIFFS.remove("/TEST.TXT");

  SPIFFS.end();
#endif
  const char *script_data = NULL; //SPIFFSでデータを読み込む
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaL_loadstring(L, script_data);
  lua_pcall(L, 0, 0, 0);
}

void loop()
{
  // put your main code here, to run repeatedly:
}