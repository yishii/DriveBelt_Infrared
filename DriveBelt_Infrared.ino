#define FREQ (40000)
#define TIME_LONG 680
#define TIME_SHORT 500



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

inline void send_1(void) {
  tone(13, FREQ);
  delayMicroseconds(190);
  noTone(13);
  delayMicroseconds(1550);

}

inline void send_0(void)
{
  tone(13, FREQ);
  delayMicroseconds(650);
  noTone(13);
  delayMicroseconds(500);

}

void send_command(int flag, int code)
{
  int i;
  // start code

  tone(13, FREQ);
  delayMicroseconds(2700);
  noTone(13);
  delayMicroseconds(550);

  send_0();
  send_0();

  if (flag) {
    send_1();
  } else {
    send_0();
  }
  // ------------------------------------------

  for (i = 0; i < 8; i++) {
    if (code & (1 << (7-i))) {
      send_1();
    } else {
      send_0();
    }
  }

  tone(13, FREQ);
  delayMicroseconds(190);
  noTone(13);
}

void loop() {
#if 0
  static int code_no = 0;

  if(Serial.available() != 0){
    Serial.println(code_no);
    send_command(0, code_no++);
    Serial.read();
  }
#endif
  send_command(0, 0x05);      

  // 05 39 speed
  // 06 wild
  // 07 technique
  // 0A formula
  // 0C type tridron
  // 0D fruits
  // 0E special
  // 0f special

  // 14 max flare
  // 15 spike
  // 16 midnight shadow
  // 17 justice hunter
  // 18 dream vegas
  // 19 cab
  // 1a massive monster
  // 1b ramble dump
  // 1c mad doctor
  // 1d burning solar
  // 1e colorful commercial
  // 1f fucking reccer
  // 20 fire braver
  // 21 rolling gravity
  // 22 spin mixer
  // 23 deco traveller
  // 24 road winter
  // 25 amazing circus
  // 2d formula 01
  // 2e formula 02
  // 2f formula 03
  // 33 reverse R
  // 3a mega max flare
  // 3b special car
  // 3c max movie
  // 3d midnight movie
  // 3e gamba rider
  // 3f dream candy
  // 40 rolling gashapon
  // 0,0 remove
  // 0,4 dead heat
  
    
  // 08 09 0b 04 03 02 01 00 10 11 12 04 13 26 27-2c 30 41-4e none
  
  delay(1000);
}
