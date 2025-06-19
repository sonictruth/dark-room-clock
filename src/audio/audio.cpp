#include "audio.h"
const char* startSound = "NokiaTun:d=4,o=5,b=225:8e6,8d6,f#,g#,8c#6,8b,d,e,8b,8a,c#,e,2a";

const char *songs[] = {
    "Agado:d=8,o=5,b=125:b,g#,4e,e,e,4e,e,e,e,e,d#,e,4f#,a,f#,4d#,d#,d#,4d#,d#,d#,d#,d#,c#,d#,4e",
    "Ba Ba:d=8,o=5,b=150:c,4p,c,4p,g,4p,g,4p,4a,4b,4c6,4a,4g,4p,f,4p,f,4p,e,4p,e,4p,d,4p,d,4p,4c",
    "Back :d=16,o=5,b=200:4g.,p,4c.,p,2f#.,p,g.,p,a.,p,8g,p,8e,p,8c,p,4f#,p,g.,p,a.,p,8g.,p,8d.,p,8g.,p,8d.6,p,4d.6,p,4c#6,p,b.,p,c#.6,p,2d.6",
    "Barbi:d=8,o=5,b=125:g#,e,g#,c#6,4a,4p,f#,d#,f#,b,4g#,f#,e,4p,e,c#,4f#,4c#,4p,f#,e,4g#,4f#",
    "Batma:d=8,o=5,b=180:d,d,c#,c#,c,c,c#,c#,d,d,c#,c#,c,c,c#,c#,d,d#,c,c#,c,c,c#,c#,f,p,4f",
    "Be bo:d=8,o=5,b=180:a,p,a,e,g,p,a,p,a,p,a,p,g,p,a,4p,a,a,e,g,p,a,p,a,p,a,p,g,p,a",
    "Betho:d=4,o=5,b=160:c,e,c,g,c,c6,8b,8a,8g,8a,8g,8f,8e,8f,8e,8d,c,e,g,e,c6,g.",
    "Birdy:d=16,o=5,b=100:g,g,a,a,e,e,8g,g,g,a,a,e,e,8g,g,g,a,a,c6,c6,8b,8b,8a,8g,8f,f,f,g,g,d,d,8f,f,f,g,g,d,d,8f,f,f,g,g,a,b,8c6,8a,8g,8e,4c",
    "Borte:d=16,o=5,b=160:b,p,c6,p,d6,b,g,e,b,g,e,c,g,e,c,a4,4p,c6,p,d6,p,e6,c6,a,f,c6,a,f,d,a,f,d,b4,2p,g6,e6,c6,a,f,d,b4,c6,a,f,d,b4,f,d,b4,f,4e.",
    "Canti:d=8,o=5,b=250:a,p,d6,p,a,p,d6,p,a,d6,p,a,p,g#,4a,a,g#,a,4g,f#,g,f#,4f.,d.,16p,4p.,a,p,d6,p,a,p,d6,p,a,d6,p,a,p,g#,a,p,g,p,4g.,f#,g,p,c6,4a#,4a,4g",
    "Coca :d=16,o=5,b=125:f#6,p,f#6,p,f#6,p,f#6,p,4g6,f#6,p,4e6,p,e6,p,8a6,4f#6,4d6",
    "Colon:d=8,o=5,b=140:g,e,4p,p,e,f,g,e6,p,e6,p,2c6,g,e,4p,p,e,f,e,g,p,g,p,2f,f,d,4p,p,d,e,f,g,e,4p,p,e,f#,e,d,g,p,e,f#,d,p,a,g.,16f#,g,a,g,f,e,d",
    "Death:d=4,o=5,b=100:4c,16p,c,8c,32p,2c,d#,8d,32p,d,8c,32p,c,8b4,32p,2c.",
    "Deep :d=8,o=5,b=160:d.4,f4,16d4,g4,16f4,d.4,f4,16d4,g4,16f4,d4",
    "Digim:d=8,o=5,b=112:c,g,f#,p,16c,16c,g,f#,g,16c,16c,g,f#,g,a#,a#,4p,c,g,f#,p,16c,16c,g,f#,g,16c,16c,g,f#,d#,4c",
    "Dont:d=16,o=5,b=125:f,e,f,e,f,e,8d,e,d,e,d,e,d,c,d,4d",
    "Drago:d=16,o=5,b=140:4f6,48f.6,4g#6,4c7,48f.7,4g#6,4c7,48f.7,2p,2f6,2f,2f6,48f.,48f.,48f.,48f.,48f.,48f.,32p,48d#.6,48d#.,48d#.6,48d#.,48d#.,48d#.,48d#.,48d#.,48d#.,32€,48f.6,48f.,48f.6,48f.,48f.,48f.,48f.,48f.,48f.,6p,8f,8f7,8f6,8f,8f7,48f.6,48f.6,48f.6,48f.6,48f.6,48f.6,48f.6,p,a#,a#,p,c6,c,c6",
    "Duell:d=8,o=5,b=200:c#,d,4e,4c#,4d,4b4,4c#,4a4,4b4,4p,16c#6,16p,16d6,16p,e6,p,c#6,p,d6,p,b,p,c#6,p,a,p,4b,4p,4a4,4a4,4b4,4c#,4a4,4c#,4b4,4p,a,p,a,p,b,p,c#6,p,a,p,c#6,p,b",
    "Dustm:d=16,o=5,b=140:8a.,a,b,p,c6,p,8c#6,4p,8e6,c#6,p,c#6,p,c#6,p,c#6,p,c#6,p,4c#6,c#6,p,c#6,p,c#6,p,d6,p,c#6,p,4b,b,p,b,p,b,p,b,p,b,p,b,p,b,p,8b.,p,e6,e6,e6,p,d6,p,c#6,p,b,p,4a",
    "Flint:d=8,o=5,b=200:g#,4c#,p,4c#6,a#,4g#,4c#,p,4g#,f#,f,f,f#,g#,4c#,4d#,2f,2p,4g#,4c#,p,4c#6,a#,4g#,4c#,p,4g#,f#,f,f,f#,g#,4c#,4d#,2c#",
    "Fragg:d=8,o=5,b=112:c6,16c6,c6,16c6,a,2p,b,b,a,g,16e6,d6,c6,16a,g,c6,16c6,c6,16d6,a,2p,b,16b,a,16b,c6",
    "Funky:d=8,o=4,b=125:c6,c6,a#5,c6,p,g5,p,g5,c6,f6,e6,c6,2p,c6,c6,a#5,c6,p,g5,p,g5,c6,f6,e6,c6",
    "Ghost:d=8,o=5,b=145:16c6,32p,16c6,e6,c6,d6,a#,2p,32c6,32p,32c6,32p,c6,a#,c6",
    "Hallo:d=8,o=5,b=180:d6,g,g,d6,g,g,d6,g,d#6,g,d6,g,g,d6,g,g,d6,g,d#6,g,c#6,f#,f#,c#6,f#,f#,c#6,f#,d6,f#,c#6,f#,f#,c#6,f#,f#,c#6,f#,d6,f#",
    "Henry:d=8,o=6,b=355:g,p,d,p,d7,p,b5,p,16b5,16b,p,16c,16g,p,d,p,g,p,d,p,d7,p,b,p,16b5,16g,p,16c,16a,p,c,p,b,p,c,p,g,p,d,p,d7,p,b5,p,16b5,16b,p,16c,16g,p,d,p,g,p,d,p,d7,p,b,p,16b5,16g,p,16c,16a,p,c,p,b,p,c,p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16b5,b,16p,16c,c7,16p,16c#,d7,16p,16d,d#7,16p,16e7,e",
    "Hitch:d=16,o=5,b=200:c,p,f4,8p,8f,32g,32p,f,32p,e,32p,d,32p,e,8p,f,32p,g,8p.,c,p,f4,8p,8f,32g,32p,f,32p,e,32p,d,32p,e,8p,f,32p,g,8p.,c,p,f4,8p,g#,32p,8c6,p,a#,32p,g#,8p,c6,32p,8d#6,p,c#6,32p,c6,8p,d#6,32p,8g6,p,f6,32p,e6,32p,c#6,32p,c6,32p,a#,32p,g#,32p,g,32p,8f4",
    "Hunte:d=4,o=5,b=500:a#4,c#,f,a#,c#6,f6,a6,f6,d#6,c#6,c6,a#,d#,f#,a#,c#6,2f6,2d#6,p,f#,a,c6,d#6,2f#6,2f6,d#6,c#6,c6,a#4,c#,f,a#,2c#6,2a#.",
    "If I :d=8,o=5,b=160:g,f,g,f,e,p,4c,4p,e,f,g,f,g,f,e,f,g,a,a#,a,a#,a,2g.,4p,4g#,4g,4f#,4f,d#,d,c,d,4d#,4p,d#,d,c,d,4d#,4c,4g,4p",
    "Itchy:d=8,o=5,b=160:c6,a,4p,c6,a6,4p,c6,a,c6,a,c6,a6,4p,p,c6,d6,e6,p,e6,f6,g6,4p,d6,c6,4d6,f6,4a#6,4a6,2c7",
    "Jesus:d=8,o=5,b=100:f,d,2a#4,4g,d#,2a#4,4g#,f,g#,4g,f,d#,4f,d,4a#4.",
    "Knigh:d=32,o=5,b=63:16e,f,e,8b,16e6,f6,e6,8b,16e,f,e,16b,16e6,4d6,8p,4p,16e,f,e,8b,16e6,f6,e6,8b,16e,f,e,16b,16e6,4f6",
    "Let i:d=8,o=5,b=100:16e6,d6,4c6,16e6,g6,a6,g.6,16g6,g6,e6,16d6,c6,16a,g,4e.6,4p,e6,16e6,f.6,e6,e6,d6,16p,16e6,16d6,d6,2c.6.",
    "Light:d=8,o=5,b=140:b,16g,16a,b,d6,c6,b,a,g,a,16f,16a,c6,f6,16d6,16c6,16a#,16g,g#,g,g#,16g,16a,b,c#6,16b,16a,16g,16f,e,f,4a",
    "Macar:d=8,o=5,b=180:f,f,f,4f,f,f,f,f,f,f,f,a,c,c,4f,f,f,4f,f,f,f,f,f,f,d,c,4p,4f,f,f,4f,f,f,f,f,f,f,f,a,4p,2c.6,4a,c6,a,f,4p,2p",
    "Magic:d=16,o=5,b=100:4c6,c6,p,8c6,4g,4g,4a,a,p,8a,2f,4a#,a,p,8a,4f,8f.,4b.,b,p,8b,2g",
    "Missi:d=16,o=5,b=100:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c6,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c6,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,p,a#4,c",
    "Nut m:d=8,o=5,b=140:a#,p,a#,a#,a#,c6,p,c6,p,d6,p,a#,p,2c6,a#,p,a#,a#,16a#.,c6,16p,c6,p,d6,p,a#,p,4c.6,16p,16c,g#,16p,16a#,g#,16p,16g,f,16p,16d#,d,16p,16a#4,g,16p,16g#,g,16p,16f,d#,16p,16d,c,16p,16d#,d,16p,16c,b4,16p,16f,d#,16p,16d,c,16p,16g,g#,16p,16g,f,16p,16d#,16a#,p,32f,32g#,16a#.",
    "On Il:d=8,o=5,b=100:d,g.,16g,g,d,4g,p,a,b.,16b,b,a,4b,p,b,4a,4g,4g,4f#,2g",
    "Picco:d=8,o=5,b=320:d6,4g6,4g,4g6,d6,e6,d6,b,4g,4d,g,a,b,c6,4d6,4g6,1d6,4d6,4g6,4g,4g6,d6,e6,b,4g,4d,f,g,a,b,4c6,4f6,1c6",
    "Pilip:d=16,o=5,b=160:e,p,e,p,g,p,g,p,b4,c#,d,p,g,p,g,p,e,p,e,p,g,p,g,p,b,g,b,e6,8d#6,8p,d#6,d6,b,a#,d#6,d6,b,a#,d#6,d6,b,a#,b,c6,d6,d#6,b,a#,g,f#,e,d#,c,b4,e,f#,d#,b4,8e,p",
    "Pinky:d=16,o=6,b=200:b.5,p,8e.,p,d#.,p,8e.,p,g.,p,4d#.,4p,b.5,p,8e.,p,d#.,p,8e.,p,g.,p,4d#.,4p,4e,8p,8e.,p,g.,p,8a#.,p,4a#,8p,a#.,p,8b.,p,a.,p,4g,8p,4f#,4p,e.,p,8a.,p,g#.,p,8a.,p,b.,p,4g#,4p,e.,p,8a.,p,g#.,p,8a.,p,b.,p,4g#,4p,c.,p,8b.5,p,8b.5,8p,b.5,p",
    "Popco:d=16,o=5,b=160:a,p,g,p,a,p,e,p,c,p,e,p,8a4,8p,a,p,g,p,a,p,e,p,c,p,e,p,8a4,8p,a,p,b,p,c6,p,b,p,c6,p,a,p,b,p,a,p,b,p,g,p,a,p,g,p,a,p,f,8a,8p,a,p,g,p,a,p,e,p,c,p,e,p,8a4,8p,a,p,g,p,a,p,e,p,c,p,e,p,8a4,8p,a,p,b,p,c6,p,b,p,c6,p,a,p,b,p,a,p,b,p,g,p,a,p,g,p,a,p,b,4c6",
    "Popey:d=8,o=6,b=160:a5,c,c,c,4a#5,a5,4c,2p,c,d,a#5,d,4f,d,2c,p,c,d,a#5,d,f,e,d,c,d,c,a5,f5,a5,c,d,c,4a#5,g5,2f5",
    "Postm:d=16,o=5,b=100:f#,p,a,p,8b,8p,f#,p,a,p,8b,8p,f#,p,a,p,b,p,d6,d6,c#6,c#6,a,p,4b.,8p,32f#,g,p,a,p,b,p,g,p,8f#.,8e,8p,32f#,g,p,a,p,32b.,32b.,g,p,8f#.,8e,8p,32f#,g,p,a,p,b,p,g,p,f#,p,e,p,d,p,c#,p,2d",
    "Postm:d=16,o=5,b=100:f#,p,a,p,8b,8p,f#,p,a,p,8b,8p,f#,p,a,p,b,p,d6,d6,c#6,c#6,a,p,4b.,8p,48f#.,g,r,a,p,b,p,g,p,8f#.,8e,8p,48f#.,g,p,a,p,32b.,32b.,g,p,8f#.,8e,8p,48f#.,g,p,a,p,b,p,g,p,f#,p,e,p,d,p,c#,p,2d",
    "Rhuba:d=8,o=5,b=180:e,f,g,4d#.,e,f,g,4d#.,e,f,g,4a#,a#,2g.,e,f,g,4d#.,e,f,g,4d#.,4e,e,4d,d,2c.",
    "Rich :d=8,o=6,b=112:e,e,e,e,e,e,16e5,16a5,16c,16e,d#,d#,d#,d#,d#,d#,16f5,16a5,16c,16d#,4d,c,a5,c,4c,2a5,32a5,32c,32e,a6",
    "Ring :d=16,o=6,b=350:b5,d,b5,d,b5,d,b5,d,d,f,d,f,d,f,d,f,f,a,f,a,f,a,f,a.",
    "Ring :d=16,o=5,b=355:b4,d,b4,d,b4,d,b4,d,d,f,d,f,d,f,d,f,f,a,f,a,f,a,f,a",
    "Rule :d=8,o=5,b=100: e.,e,f,4f,e,f.,16e,d.,16c,2b4,4g,4f,16e,16c,16f,16d,g,f,4e,d.,16c,4c",
    "Scatm:d=16,o=5,b=200:8b,b,32p,8b,b,32p,8b,2d6,p,c#.6,p.,8d6,p,c#6,8b,p,8f#,2p.,c#6,8p,d.6,p.,c#6,b,8p,8f#,2p,32p,2d6,p,c#6,8p,d.6,p.,c#6,a.,p.,8e,2p.,c#6,8p,d.6,p.,c#6,b,8p,8b,b,32p,8b,b,32p,8b,2d6,p,c#.6,p.,8d6,p,c#6,8b,p,8f#,2p.,c#6,8p,d.6,p.,c#6,b,8p,8f#,2p,32p,2d6,p,c#6,8p,d.6,p.,c#6,a.,p.,8e,2p.,c#6,8p,d.6,p.,c#6,a,8p,8e,2p,32p,f#.6,p.,b.,p.",
    "Simps:d=8,o=5,b=160:c.6,4e6,4f#6,a6,4g.6,4e6,4c6,a,f#,f#,f#,2g,p,p,f#,f#,f#,g,4a#.,c6,c6,c6,4c6",
    "South:d=8,o=5,b=125:e,e,e,16e,e,16e,p,e,e,e,e,e,16p,16e,e,2p,g,g,4g,16b,16b,b,e,a#,16g,16g,g,16f#,16f#,f#,e",
    "Spide:d=4,o=6,b=200:c,8d#,g.,p,f#,8d#,c.,p,c,8d#,g,8g#,g,f#,8d#,c.,p,f,8g#,c.7,p,a#,8g#,f.,p,c,8d#,g.,p,f#,8d#,c,p,8g#,2g,p,8f#,f#,8d#,f,8d#,2c",
    "Star :d=16,o=5,b=63:8f.,a#,4d#.6,8d6,a#.,g.,c.6,4f6",
    "Take :d=8,o=5,b=160:f#,f#,f#,d,p,b4,p,e,p,e,p,e,g#,g#,a,b,a,a,a,e,p,d,p,f#,p,f#,p,f#,e,e,f#,e,f#,f#,f#,d,p,b4,p,e,p,e,p,e,g#,g#,a,b,a,a,a,e,p,d,p,f#,p,f#,p,f#,e,e5",
    "Teena:d=8,o=6,b=100:g5,a5,g5,a5,g5,16a5,g.5,a5,a#5,c,a#5,c,a#5,16c,a#.5,c,d#,f,d#,f,d#,16f,d#.,f,16c,16c,16c,16c,a#5,4c,16c7,16c7,16c7",
    "The A:d=8,o=5,b=132:4d#6,a#,2d#6,16p,g#,4a#,4d#.,p,16g,16a#,d#6,a#,f6,2d#6,16p,c#.6,16c6,16a#,g#.,2a#.",
    "Time :d=16,o=5,b=80:8c,d,e,d,e,f#,g,f#,g,a,g,e,a,b,4c6,4b",
    "To Th:d=8,o=5,b=270:c,c,4c,c,c,4c,c,c,f,p,g,p,4a,c,c,4c,c,c,4c,a,a,g,p,e,p,4c,c,c,4c,c,c,4c,c,c,f,p,g,p,4a,f,a,1c6,a,g,f,p,a.,p,f",
    "Tocca:d=16,o=5,b=160:a,g,1a,g,f,e,d,2c#,p,2d,2p,a,g,1a,8e.,4f,2c#,2d",
    "Top C:d=16,o=5,b=125:8g,8c6,p,g,8c6,c6,8g,8c6,p,8c6,g,g,f#,g,g#,a,a#,b,8c6,8c6,p,g,4g,48g#.,48a.,48a#.,48b.,c6,p,c6,8c6,a,8b,a,8g,8c6,p,8c6,p,d#,8e,g,8a,c6,8p,c6,8c6,a,8b,a,8g",
    "Trans:d=16,o=6,b=285:e7,f7,e7,d#7,4d7,4p,d,d,d,d,d,d,d,d,e,e,e,e,f,f,f,f,f,f,f,f,8a7,8a#7,8a7,8p,4d7,2p,d,d7,d,d7,d,d7,d,d7,e,e7,e,e7,f,f7,f,f7,f,f7,f,f7,a5,a5,a5,a5,a#5,a#,a#5,a#,a#5,a#,a#5,a#,a#5,a#,a#5,a#,4p,8d,8p,4e,4f,4p,4f,4p,2g,4a,4a#,4p,g,g7,g,g7,g,g7,g,g7,4e,4g,4a,4p,f,f7,f,f7,f,f7,f,f7,4e,4f,4g,4p,e,e7,e,e7,e,e7,e,e7,e,e7,e,e7,4p,4d,4c#,8e,8p,4d,2d,d,d7,d,d7,d,d7,d,d7",
    "Trim :d=16,o=5,b=350:a,b,a,b,a,b,a,4p,a,b,a,b,a,b,a,b,a.",
    "Under:d=4,o=6,b=200:8d,8f,8a#,d7,d7,8a#,c7,d#7,d7,a#,8a#5,8d,8f,a#,a#,8c,a,c7,a#,p,8d,8f,8a#,d7,d7,8a#,c7,d#7,d7,a#,8a#5,8d,8f,a#,a#,8c,a,c7,16a#,16d,16a#,16d,16a#,16d,16a#",
    "Vanes:d=16,o=5,b=140:c6,b,8c6,g,p,g,p,d#,p,d#,p,c,p,c,p,c6,b,8c6,g#,p,g#,p,f,p,8f,c,p,c,p,c6,b,8c6,g,p,g,p,d#,p,d#,p,c,p,c,p,g,f,d#,d,c,d,d#,c,d#,f,8g,8p,8d6,c6,d6,a#,d6,a,d6,g,d6,d6,p,d6,p,d6,p,8d6,c6,d6,a#,d6,a,d6,g,d6,d6,p,d6,p,d6,p,g,f,d#,d,c,d,d#,c,d#,f,4c.",
    "Walk :d=8,o=5,b=160:4g.,32p,4g,4p.,d,e,4g,e,4d,4c.,4c,2p,d,e,4g.,4g,4p.,d,e,4g,e,4d,4c.,4c",
    "Wanna:d=8,o=5,b=125:16g,16g,16g,16g,g,a,g,e,p,16c,16d,16c,d,d,c,4e,4p,g,g,g,a,g,e,p,4c6,c6,b,g,a,16b,16a,4g",
    "Wolf :d=16,o=5,b=900:8a4,a#4,b4,c,c#,d,d#,e,f,f#,g,g#,a,a#,b,c6,8c#6,d6,d#6,e6,f6,4p,4p,a4,a#4,b4,c,c#,d,d#,e,f,f#,g,g#,a,a#,b,a#,a,g#,g,f#,f,e,d#,d,c#,c,b4,a#4,a4",
};

void waitForBuzzerRelease()
{
  while (digitalRead(BUZZER_PIN) == LOW)
  {
  }
}

void playBeep()
{
  pinMode(BUZZER_PIN, OUTPUT);
  anyrtttl::blocking::play(BUZZER_PIN, ":d=60,o=3,b=400:c");
  pinMode(BUZZER_PIN, INPUT_PULLUP);
  waitForBuzzerRelease();
}

void playBeep1()
{
  pinMode(BUZZER_PIN, OUTPUT);
  anyrtttl::blocking::play(BUZZER_PIN, ":d=40,o=5,b=300:a,g");
  pinMode(BUZZER_PIN, INPUT_PULLUP);
  waitForBuzzerRelease();
}

void playBeep2()
{
  pinMode(BUZZER_PIN, OUTPUT);
  anyrtttl::blocking::play(BUZZER_PIN, ":d=30,o=5,b=300:f,c,f");
  pinMode(BUZZER_PIN, INPUT_PULLUP);
  waitForBuzzerRelease();
}

void playAlarm()
{
  int songCount = sizeof(songs) / sizeof(songs[0]);
  int randomIndex = random(songCount);
  playSong(songs[randomIndex]);
}

void playStartSound()
{
  playSong(startSound);
}

void playSong(const char *song)
{
  pinMode(BUZZER_PIN, OUTPUT);
  anyrtttl::blocking::play(BUZZER_PIN, song);
  pinMode(BUZZER_PIN, INPUT_PULLUP);
  waitForBuzzerRelease();
}
