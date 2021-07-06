
#include <TFT_eSPI.h>
// #include "Free_Fonts.h"

TFT_eSPI tft;

enum {
 STATIC_IP_CFG,
 DHCP,
 TESTING,
};

#define SYM_SPACE 41
#define SYM_COLON 42
#define SYM_AT 43

#define SYM_PLUS 44
#define SYM_MINUS 45
#define SYM_PROD 46
#define SYM_SLASH 47
#define SYM_EQ 48

#define SYM_COMMA 49
#define SYM_EXCLAM 50
#define SYM_DOT 51
#define SYM_QUESTION 52

static unsigned char mfont[][9] = {
  [0] = {0x00, 0x1c, 0x36, 0x36, 0x36, 0x36, 0x36, 0x1c},
  [1] = {0x00, 0x0c, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c},
  [2] = {0x00, 0x3c, 0x06, 0x06, 0x1c, 0x30, 0x30, 0x3e},
  [3] = {0x00, 0x3c, 0x06, 0x06, 0x1c, 0x06, 0x06, 0x3c},
  [4] = {0x00, 0x06, 0x0e, 0x16, 0x26, 0x3e, 0x06, 0x06},
  [5] = {0x00, 0x3c, 0x20, 0x3c, 0x06, 0x06, 0x06, 0x3c},
  [6] = {0x00, 0x1c, 0x30, 0x3c, 0x36, 0x36, 0x36, 0x1c},
  [7] = {0x00, 0x3e, 0x06, 0x0c, 0x0c, 0x18, 0x18, 0x18},
  [8] = {0x00, 0x1c, 0x36, 0x36, 0x1c, 0x36, 0x36, 0x1c},
  [9] = {0x00, 0x1c, 0x36, 0x36, 0x36, 0x1e, 0x06, 0x1c},
  [10] = {0x00, 0x1c, 0x36, 0x36, 0x36, 0x3e, 0x36, 0x36}, /* A */
  [11] = {0x00, 0x3c, 0x36, 0x3c, 0x36, 0x36, 0x36, 0x3c},
  [12] = {0x00, 0x1e, 0x30, 0x30, 0x30, 0x30, 0x30, 0x1e},
  [13] = {0x00, 0x3c, 0x36, 0x36, 0x36, 0x36, 0x36, 0x3c},
  [14] = {0x00, 0x3e, 0x30, 0x3c, 0x30, 0x30, 0x30, 0x3e},
  [15] = {0x00, 0x3e, 0x30, 0x3c, 0x30, 0x30, 0x30, 0x30},
  [16] = {0x00, 0x1c, 0x30, 0x30, 0x36, 0x36, 0x36, 0x3e},
  [17] = {0x00, 0x36, 0x36, 0x3e, 0x36, 0x36, 0x36, 0x36}, /* H */
  [18] = {0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c},
  [19] = {0x00, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1c},
  [20] = {0x00, 0x33, 0x36, 0x3c, 0x38, 0x3c, 0x36, 0x33},
  [21] = {0x00, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3c},
  [22] = {0x00, 0x41, 0x63, 0x77, 0x7f, 0x6b, 0x63, 0x63},
  [23] = {0x00, 0x23, 0x33, 0x3b, 0x3f, 0x37, 0x33, 0x31},
  [24] = {0x00, 0x1e, 0x33, 0x33, 0x33, 0x33, 0x33, 0x1e}, /* O */
  [25] = {0x00, 0x1e, 0x1b, 0x1b, 0x1b, 0x1e, 0x18, 0x18},
  [26] = {0x00, 0x1e, 0x33, 0x33, 0x33, 0x33, 0x37, 0x1e, 0x03}, /* Q */
  [27] = {0x00, 0x3c, 0x36, 0x36, 0x36, 0x3c, 0x34, 0x36},
  [28] = {0x00, 0x0e, 0x18, 0x18, 0x0c, 0x06, 0x06, 0x1c},
  [29] = {0x00, 0x3f, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c},
  [30] = {0x00, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x1c},
  [31] = {0x00, 0x66, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x18},
  [32] = {0x00, 0x63, 0x63, 0x6b, 0x7f, 0x3e, 0x3e, 0x36}, /* W */
  [33] = {0x00, 0x33, 0x33, 0x1e, 0x0c, 0x1e, 0x33, 0x33},
  [34] = {0x00, 0x33, 0x33, 0x1e, 0x0c, 0x0c, 0x0c, 0x0c},
  [35] = {0x00, 0x3e, 0x06, 0x0e, 0x1c, 0x38, 0x30, 0x3e},
  [36] = {0x00},
  [37] = {0x00},
  [38] = {0x00},
  [39] = {0x00},
  [40] = {0x00},
  [SYM_SPACE] = {0x00},
  [SYM_COLON] =    {0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00},
  [SYM_AT] =       {0x00, 0x1e, 0x33, 0x3f, 0x37, 0x3f, 0x30, 0x1e},
  [SYM_PLUS] =     {0x00, 0x00, 0x08, 0x08, 0x3e, 0x08, 0x08, 0x00},
  [SYM_MINUS] =    {0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00},
  [SYM_PROD] =     {0x0},
  [SYM_SLASH] =    {0x00, 0x04, 0x04, 0x0c, 0x08, 0x18, 0x10, 0x10},
  [SYM_EQ] =       {0x00, 0x00, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x00},
  [SYM_COMMA] =    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0c, 0x08 }, /* , */
  [SYM_EXCLAM] =   {0x00, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x0c},
  [SYM_DOT] =      {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c}, /* . */
  [SYM_QUESTION] = {0x00, 0x3c, 0x06, 0x0c, 0x18, 0x18, 0x00, 0x18}, /* ? */
};

static int font_scale = 2;
static int background_color = TFT_WHITE;
static int foreground_color = TFT_BLACK;
static int line_height = 9;
static int font_width = 8;

static int repeat_delay = 150;

static uint32_t ip = 0xc0a80121;
static uint32_t peer_ip = 0xc0a801fe;

static uint32_t ip_mode = 1;
static uint32_t peer_mode = 0;

static int curst = DHCP;

static void _raw_draw_text(int x, int y, int scale, int erase, int eraseColor, const char *str)
{
  int i;
  int a;
  int b;

  for (i = 0; i < strlen(str); i++) {
    int color = foreground_color;
    unsigned char c;
    if (str[i] >= '0' && str[i] <= '9') {
      c = str[i] - '0';
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      c = str[i] - 'A' + 10;
    } else if (str[i] >= 'a' && str[i] <= 'z') {
      c = str[i] - 'a' + 10;
    } else {
      switch (str[i]) {
        case '.':
          c = SYM_DOT;
          break;
        case ' ':
          c = SYM_SPACE;
          break;
        case '@':
          c = SYM_AT;
          break;
        case ':':
          c = SYM_COLON;
          break;
        case '+':
          c = SYM_PLUS;
          break;
        case '-':
          c = SYM_MINUS;
          break;
        case '*':
          c = SYM_PROD;
          break;
        case '/':
          c = SYM_SLASH;
          break;
        case '=':
          c = SYM_EQ;
          break;
        case ',':
          c = SYM_COMMA;
          break;
        case '!':
          c = SYM_EXCLAM;
          break;
         case '?':
          c = SYM_QUESTION;
          break;
        default:
          c = str[i];
          break;
      }
    }
    if (c > SYM_QUESTION || c < 0) {
      /*
      Serial.print(str[i]);
      Serial.print(", ");
      Serial.println(c);
      */
      c = SYM_QUESTION;
      color = TFT_RED;
    }

    for (b = 0; b < 9; b++) {
      for (a = 0; a < (font_width-1); a++) {
        if (mfont[c][b] & (1<<(6-a))) {
          tft.fillRect(x+i * (scale*(font_width-1)) + a*scale, y+b*scale, scale, scale, color);
        } else if (erase) {
          tft.fillRect(x+i * (scale*(font_width-1)) + a*scale, y+b*scale, scale, scale, eraseColor);
        }
      }
    }
  }
}

static void drawText(unsigned int row, unsigned col, const char *str, int erase)
{
  _raw_draw_text(col * font_width * font_scale, row * line_height * font_scale, font_scale, erase, background_color, str);

}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(3);

  tft.fillScreen(TFT_WHITE);

  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_KEY_B, INPUT_PULLUP);
  pinMode(WIO_KEY_C, INPUT_PULLUP);

  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);

  /*
  _raw_draw_text(0, 0, 1, 0, 0, buf);
  _raw_draw_text(0, 9, 2, 0, 0, buf);
  _raw_draw_text(0, 9+18, 3, 0, 0, buf);
  _raw_draw_text(0, 9+18+27, 4, 0, 0, buf);
  */

  drawText(1, 0, "ABCDEFGHIJKLM", 1);
  drawText(2, 0, "NOPQRSTUVWXYZ", 1);
  drawText(3, 0, "+-*/=@:,.?", 1);

  {
    int i;
    drawText(4, 0, "booting", 0);
    for (i = 0; i < 10; i++) {
      drawText(4, 7 + i, ".", 0);
      delay(200);
    }
    // wait until ok signal
  }

  tft.fillScreen(TFT_WHITE);

  font_scale = 4;
  drawText(3, 1+(10-3)/2, "OK!", 0);

  delay(500);

  font_scale = 2;
  tft.fillScreen(TFT_WHITE);

  redraw();
  /*

  char buf[21];
  sprintf(buf, "IP: %3d.%3d.%3d.%3d", 0xff & (ip >> 24), 0xff & (ip >> 16), 0xff & (ip >> 8), 0xff & ip);
  drawText(4, 0, buf, 0);
  sprintf(buf, "GW: %3d.%3d.%3d.%3d", 0xff & (peer_ip >> 24), 0xff & (peer_ip >> 16), 0xff & (peer_ip >> 8), 0xff & peer_ip);
  drawText(5, 0, buf, 0);

  */

}

struct button {
  int last_state;
  long last_millis;
};

static struct button btn_up;
static struct button btn_down;
static struct button btn_left;
static struct button btn_right;
static struct button btn_prs;

static struct button btn_a;
static struct button btn_b;
static struct button btn_c;

static void drawDHCPscreen()
{
  int color = foreground_color;
  foreground_color = TFT_BLUE;
  int fs = font_scale;
  drawText(0, 0, "DHCP mode  ", 1);
  font_scale = fs;
  foreground_color = color;

  fs = font_scale;
  // drawText Here
  font_scale = fs;
}

static void drawTestingscreen()
{
  int i;
  int color = foreground_color;
  foreground_color = TFT_BLUE;
  int fs = font_scale;
  drawText(0, 0, "Testing    ", 1);
  font_scale = fs;
  foreground_color = color;
  fs = font_scale;
  font_scale = 1;
  for (i = 2; i < 25; i++) {
    drawText(i, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/=@:.,", 1);
  }
  font_scale = fs;
}

static void drawStaticIPCFGscreen()
{
  char buf[21];
  int color = foreground_color;

  foreground_color = TFT_BLUE;
  int fs = font_scale;
  drawText(0, 0, "Static mode", 1);
  font_scale = fs;
  foreground_color = color;

  fs = font_scale;
  font_scale = 2;
  sprintf(buf, "IP: %3d.%3d.%3d.%3d  ", 0xff & (ip >> 24), 0xff & (ip >> 16), 0xff & (ip >> 8), 0xff & ip);
  drawText(4, 0, buf, 1);
  sprintf(buf, "GW: %3d.%3d.%3d.%3d  ", 0xff & (peer_ip >> 24), 0xff & (peer_ip >> 16), 0xff & (peer_ip >> 8), 0xff & peer_ip);
  drawText(5, 0, buf, 1);
  font_scale = fs;
}

static void redraw()
{
  /*
    _raw_draw_text(0, 0, 1, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9, 2, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9+18, 3, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9+18+27, 4, 1, TFT_WHITE, buf);
  */

  switch (curst) {
    case STATIC_IP_CFG:
      drawStaticIPCFGscreen();
      break;
    case DHCP:
      drawDHCPscreen();
      break;
    case TESTING:
      drawTestingscreen();
      break;
    default:
      break;
  }
}



void loop() {
  /*
  int c = Serial.read();
  if (c == -1) {
    return;
  }
  // put your main code here, to run repeatedly:
  switch (c) {
    case 'R':
      tft.fillScreen(TFT_RED);
      break;
    case 'G':
      tft.fillScreen(TFT_GREEN);
      break;
    case 'B':
      tft.fillScreen(TFT_BLUE);
      break;
    default:
      tft.fillScreen(TFT_WHITE);
      break;
  }
  // Serial.println("c="+c);
  */
  int st;

  st = digitalRead(WIO_5S_UP);
  if ((btn_up.last_state != LOW || millis() - btn_up.last_millis > repeat_delay) && st == LOW) {
    if (ip_mode) {
      ip += ip_mode;
    } else if (peer_mode) {
      peer_ip += peer_mode;
    }
    redraw();
    btn_up.last_millis = millis();
  }
  btn_up.last_state = st;

  st = digitalRead(WIO_5S_DOWN);
  if ((btn_down.last_state != LOW || millis() - btn_down.last_millis > repeat_delay) && st == LOW) {
    if (ip_mode) {
      ip -= 1;
    }
    else if (peer_mode) {
      peer_ip -= peer_mode;
    }
    redraw();
    btn_down.last_millis = millis();
  }
  btn_down.last_state = st;

  st = digitalRead(WIO_5S_LEFT);
  if ((btn_left.last_state != LOW /*|| millis() - btn_left.last_millis > repeat_delay*/) && st == LOW) {
    if (ip_mode > 0 && ip_mode < 16777216) {
      ip_mode <<= 8;
    }
    else if (peer_mode > 0 && peer_mode < 16777216) {
      peer_mode <<= 8;
    }
    else if (peer_mode == 16777216) {
      peer_mode = 0;
      ip_mode = 1;
    }
    redraw();
    btn_left.last_millis = millis();
  }
  btn_left.last_state = st;

  st = digitalRead(WIO_5S_RIGHT);
  if ((btn_right.last_state != LOW /*|| millis() - btn_right.last_millis > repeat_delay*/) && st == LOW) {
    if (ip_mode > 1) {
      ip_mode >>= 8;
    }
    else if (peer_mode > 1) {
      peer_mode >>= 8;
    }
    else if (ip_mode == 1) {
      peer_mode = 16777216;
      ip_mode = 0;
    }
    redraw();
    btn_right.last_millis = millis();
  }
  btn_right.last_state = st;

  st = digitalRead(WIO_5S_PRESS);
  if ((btn_prs.last_state != LOW || millis() - btn_prs.last_millis > repeat_delay) && st == LOW) {
    redraw();
    btn_prs.last_millis = millis();
  }
  btn_prs.last_state = st;

  st = digitalRead(WIO_KEY_A);
  if ((btn_a.last_state != LOW || millis() - btn_a.last_millis > repeat_delay) && st == LOW) {
    curst = TESTING;
    redraw();
    btn_a.last_millis = millis();
  }
  btn_a.last_state = st;

  st = digitalRead(WIO_KEY_B);
  if ((btn_b.last_state != LOW || millis() - btn_b.last_millis > repeat_delay) && st == LOW) {
    curst = STATIC_IP_CFG;
    redraw();
    btn_b.last_millis = millis();
  }
  btn_b.last_state = st;

  st = digitalRead(WIO_KEY_C);
  if ((btn_c.last_state != LOW || millis() - btn_c.last_millis > repeat_delay) && st == LOW) {
    curst = DHCP;
    redraw();
    btn_c.last_millis = millis();
  }
  btn_c.last_state = st;

/*
  switch (curst) {
    case STATIC_IP_CFG:
      break;
    case DHCP:
      drawDHCPscreen();
      break;
    case TESTING:
      drawTestingScreen();
      break;
  }
*/

  // blink text, period is 1024 milis
  if (false) {
    int x = (millis() & 1023);
    if (x > 512) {
      x = 1023 - x;
    }

    int g = x * ((background_color>>5)&0x3f) / 512 + (511 - x) * 0 / 512;

    int bak_fgc = foreground_color;
    foreground_color = (0x1f << 11) | (g << 5) | (g >> 1);
    drawText(6, 0, "Testing", 0);

    foreground_color = bak_fgc;
  }

}
