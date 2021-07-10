
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
static uint32_t gw_ip = 0xc0a801fe;
static uint8_t netmask = 24;
static uint32_t dns_ip = 0x08080808;

static uint32_t ip_mode = 0;

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
  _raw_draw_text(col * (font_width-1) * font_scale, row * line_height * font_scale, font_scale, erase, background_color, str);

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

  int i;
  int fs = font_scale;
  font_scale = 1;
  for (i = 2; i < 25; i++) {
    drawText(i, 0, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-*/=@:.,", 1);
  }
  font_scale = fs;

  font_scale = 2;
  tft.fillScreen(TFT_WHITE);

  fs = font_scale;
  font_scale = 4;
  drawText(3, 1+(10-3)/2, "OK!", 0);
  font_scale = fs;

  delay(500);
  tft.fillScreen(TFT_WHITE);
  redraw(true);
  /*

  char buf[21];
  sprintf(buf, "IP: %3d.%3d.%3d.%3d", 0xff & (ip >> 24), 0xff & (ip >> 16), 0xff & (ip >> 8), 0xff & ip);
  drawText(4, 0, buf, 0);
  sprintf(buf, "GW: %3d.%3d.%3d.%3d", 0xff & (gw_ip >> 24), 0xff & (gw_ip >> 16), 0xff & (gw_ip >> 8), 0xff & gw_ip);
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
}

static void drawStaticIPCFGscreen(bool invalidate)
{
  char buf[21];
  int color = foreground_color;

  foreground_color = TFT_BLUE;
  int fs = font_scale;

  if (invalidate) {
    drawText(0, 0, "Static mode", 1);
  }
  font_scale = fs;
  foreground_color = color;

  fs = font_scale;
  font_scale = 2;
  if (invalidate) {
    sprintf(buf, "IP: %3d.%3d.%3d.%3d/%2d ", 0xff & (ip >> 24), 0xff & (ip >> 16), 0xff & (ip >> 8), 0xff & ip, netmask);
    drawText(4, 0, buf, 1);
    sprintf(buf, "GW: %3d.%3d.%3d.%3d  ", 0xff & (gw_ip >> 24), 0xff & (gw_ip >> 16), 0xff & (gw_ip >> 8), 0xff & gw_ip);
    drawText(5, 0, buf, 1);
    sprintf(buf, "DNS:%3d.%3d.%3d.%3d  ", 0xff & (dns_ip >> 24), 0xff & (dns_ip >> 16), 0xff & (dns_ip >> 8), 0xff & dns_ip);
    drawText(6, 0, buf, 1);
  }

  color = foreground_color;

#define T 1024

  int x = (millis() & (T-1));
  if (x > (T>>1)) {
    x = (T-1) - x;
  }

  int g = x * ((background_color>>5)&0x3f) / (T>>1) + (((T>>1)-1) - x) * 0 / (T>>1);

#undef T

  foreground_color = (0x1f << 11) | (g << 5) | (g >> 1);

  switch (ip_mode) {
    case 0:
    case 1:
    case 2:
    case 3:
      sprintf(buf, "%3d", 0xff & (ip >> (8*(3-((ip_mode-0)&3)))));
      drawText(4, 4+((ip_mode-0) & 3)*4, buf, 0);
      break;
    case 4:
    case 5:
    case 6:
    case 7:
      sprintf(buf, "%3d", 0xff & (gw_ip >> (8*(3-((ip_mode-4)&3)))));
      drawText(5, 4+((ip_mode-4) & 3)*4, buf, 0);
      break;
    case 8:
    case 9:
    case 10:
    case 11:
      sprintf(buf, "%3d", 0xff & (dns_ip >> (8*(3-((ip_mode-8)&3)))));
      drawText(6, 4+((ip_mode-8) & 3)*4, buf, 0);
      break;
    case 12:
      sprintf(buf, "%2d", netmask);
      drawText(4, 20, buf, 0);
      break;
  }
  foreground_color = color;

  font_scale = fs;
}

static void redraw(bool invalidate)
{
  /*
    _raw_draw_text(0, 0, 1, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9, 2, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9+18, 3, 1, TFT_WHITE, buf);
    _raw_draw_text(0, 9+18+27, 4, 1, TFT_WHITE, buf);
  */

  switch (curst) {
    case STATIC_IP_CFG:
      drawStaticIPCFGscreen(invalidate);
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

static char cmdbuf[256];
static int cmdbufoff = 0;
static int last_cmdidx = 0;

struct cmdarg {
    const char *value;
    size_t len;
};

static int handle_cmd(const struct cmdarg *arg, int idx)
{
  int err = 0;
  int i;
  char buf[52];

  if (atoi(arg[0].value) == 1) {
    // 1,scale,row,col,fg,bg,erase,text
    // 1,1,25,36,63488,0,1, off $
    // 1,1,25,36,2016,0,1, on $
    if (idx < 8) {
      return 22;
    } else {
      int osc = font_scale;
      int scale;
      if (arg[1].len == 1 && arg[1].value[0] == '-') {
      } else {
        font_scale = atoi(arg[1].value);
      }
      int row = atoi(arg[2].value);
      int col = atoi(arg[3].value);
      int ofg = foreground_color;
      if (arg[4].len == 1 && arg[4].value[0] == '-') {

      } else {
        foreground_color = atoi(arg[4].value);
      }
      int obg = background_color;
      if (arg[5].len == 1 && arg[5].value[0] == '-') {
      } else {
        background_color = atoi(arg[5].value);
      }
      int erase = atoi(arg[6].value);

      drawText(row, col, arg[7].value, erase);
      font_scale = osc;
      foreground_color = ofg;
      background_color = obg;
    }
  }
  else if (atoi(arg[0].value) == 2) {
      int osc = font_scale;
      int ofg = foreground_color;
      int obg = background_color;
      font_scale = 1;
      background_color = 0;
      if (atoi(arg[1].value) == 0) {
        foreground_color = 0xf800;
        drawText(25, 36, " off ", 1);
      } else {
        foreground_color = 0x07e0;
        drawText(25, 36, " on ", 1);
      }
      font_scale = osc;
      foreground_color = ofg;
      background_color = obg;
  } else if (atoi(arg[0].value) == 3) {
      // clear

  } else if (atoi(arg[0].value) == 4) {
      // dialog
      // 4,dialogid,msg,opt1,yes,opt2,no
      // 4,100,1,ok,2,no,are you sure?
  } else {
    Serial.println("# not implemented");
    err = 22;
  }

  return err;
}

static int do_submit(const char *cmd)
{
  int idx = 0;
  const char *tmp;
  const char *ptr = cmd;
  struct cmdarg argv[16];
  int err = 0;

  do {
    tmp = strchr(ptr, ',');
    if (idx >= sizeof(argv)/sizeof(argv[0])) {
      err = -1;
      break;
    }

    argv[idx].value = ptr;
    if (!tmp) {
      argv[idx].len = &cmd[strlen(cmd)] - ptr;
    } else {
      argv[idx].len = tmp - ptr;
    }
    idx += 1;
    ptr = tmp + 1;
  } while (tmp);

  if (err == 0) {
    err = handle_cmd(argv, idx);
  }
  return err;
}

static void do_5s_right()
{
  switch (curst) {
    case TESTING:
      Serial.println("# not implemented");
      break;
    case DHCP:
      Serial.println("# not implemented");
      break;
    case STATIC_IP_CFG:

      // 111111111111
      /*
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
      */

      Serial.println(ip_mode);
      if (ip_mode < 12) {
        ip_mode += 1;
      }
      Serial.println(ip_mode);

      break;
    default:
      break;
  }
}

static void do_5s_left()
{
  switch (curst) {
    case TESTING:
      Serial.println("# not implemented");
      break;
    case DHCP:
      Serial.println("# not implemented");
      break;
    case STATIC_IP_CFG:
      Serial.println(ip_mode);
      if (ip_mode > 0) {
        ip_mode -= 1;
      }
      Serial.println(ip_mode);
      break;
    default:
      break;
  }
}

static void do_5s_up()
{
  switch (curst) {
    case TESTING:
      Serial.println("# not implemented");
      break;
    case DHCP:
      Serial.println("# not implemented");
      break;
    case STATIC_IP_CFG:
      if (ip_mode == 12) {
        netmask += 1;
        netmask %= 32;
      } else if (ip_mode < 12 && ip_mode >= 8) {
        dns_ip += (1<<(8*(3-(ip_mode-8))));
      } else if (ip_mode < 8 && ip_mode >= 4) {
        gw_ip += (1<<(8*(3-(ip_mode-4))));
      } else if (ip_mode < 4 && ip_mode >= 0) {
        ip += (1<<(8*(3-(ip_mode-0))));
      }
      break;
    default:
      break;
  }
}

static void do_5s_down()
{
  switch (curst) {
    case TESTING:
      Serial.println("# not implemented");
      break;
    case DHCP:
      Serial.println("# not implemented");
      break;
    case STATIC_IP_CFG:
      if (ip_mode == 13) {
        netmask += 31;
        netmask %= 32;
      } else if (ip_mode < 12 && ip_mode >= 8) {
        dns_ip -= (1<<(8*(3-(ip_mode-8))));
      } else if (ip_mode < 8 && ip_mode >= 4) {
        gw_ip -=  (1<<(8*(3-(ip_mode-4))));
      } else if (ip_mode < 4 && ip_mode >= 0) {
        ip -=  (1<<(8*(3-(ip_mode-0))));
      }
      break;
    default:
      break;
  }
}


static void do_5s_enter()
{
  char buf[64];
  switch (curst) {
    case TESTING:
      Serial.println("# not implemented");
      break;
    case DHCP:
      Serial.println("dhcp_test_start,00:0C:11:11:22:33,WIO");
      break;
    case STATIC_IP_CFG:
      snprintf(buf, sizeof(buf), "static,%d.%d.%d.%d,%d,%d.%d.%d.%d,%d.%d.%d.%d",
        0xff & (ip>>24),
        0xff & (ip>>16),
        0xff & (ip>>8),
        0xff & (ip>>0),
        netmask,
        0xff & (gw_ip>>24),
        0xff & (gw_ip>>16),
        0xff & (gw_ip>>8),
        0xff & (gw_ip>>0),
        0xff & (dns_ip>>24),
        0xff & (dns_ip>>16),
        0xff & (dns_ip>>8),
        0xff & (dns_ip>>0)
      );
      Serial.println(buf);
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

    do_5s_up();
    redraw(true);
    btn_up.last_millis = millis();
  }
  btn_up.last_state = st;

  st = digitalRead(WIO_5S_DOWN);
  if ((btn_down.last_state != LOW || millis() - btn_down.last_millis > repeat_delay) && st == LOW) {
    do_5s_down();
    redraw(true);
    btn_down.last_millis = millis();
  }
  btn_down.last_state = st;

  st = digitalRead(WIO_5S_LEFT);
  if ((btn_left.last_state != LOW /*|| millis() - btn_left.last_millis > repeat_delay*/) && st == LOW) {
    do_5s_left();
    redraw(true);
    btn_left.last_millis = millis();
  }
  btn_left.last_state = st;

  st = digitalRead(WIO_5S_RIGHT);
  if ((btn_right.last_state != LOW /*|| millis() - btn_right.last_millis > repeat_delay*/) && st == LOW) {
    do_5s_right();
    redraw(true);
    btn_right.last_millis = millis();
  }
  btn_right.last_state = st;

  st = digitalRead(WIO_5S_PRESS);
  if ((btn_prs.last_state != LOW /* || millis() - btn_prs.last_millis > repeat_delay*/) && st == LOW) {
    do_5s_enter();
    redraw(true);
    btn_prs.last_millis = millis();
  }
  btn_prs.last_state = st;

  st = digitalRead(WIO_KEY_A);
  if ((btn_a.last_state != LOW || millis() - btn_a.last_millis > repeat_delay) && st == LOW) {
    curst = TESTING;
    redraw(true);
    btn_a.last_millis = millis();
  }
  btn_a.last_state = st;

  st = digitalRead(WIO_KEY_B);
  if ((btn_b.last_state != LOW || millis() - btn_b.last_millis > repeat_delay) && st == LOW) {
    curst = STATIC_IP_CFG;
    redraw(true);
    btn_b.last_millis = millis();
  }
  btn_b.last_state = st;

  st = digitalRead(WIO_KEY_C);
  if ((btn_c.last_state != LOW || millis() - btn_c.last_millis > repeat_delay) && st == LOW) {
    curst = DHCP;
    redraw(true);
    btn_c.last_millis = millis();
  }
  btn_c.last_state = st;

  switch (curst) {
    case STATIC_IP_CFG:
      redraw(false);
      break;
    case DHCP:
      break;
    case TESTING:
      break;
  }

  int c = Serial.read();
  if (c > -1) {
    // Serial.println(c);
    cmdbuf[cmdbufoff] = c;
    if (c == 0xa || c == '$') {
      // submit
      cmdbuf[cmdbufoff] = 0;
      if (!do_submit(cmdbuf)) {
        Serial.write("# OK\n");
      } else {
        Serial.write("# FAIL\n");
      }
      cmdbufoff = 0;
    } else if (cmdbufoff < sizeof(cmdbuf) - 1) {
      cmdbufoff++;
    } else {
      // submit
      cmdbuf[cmdbufoff] = 0;
      if (!do_submit(cmdbuf)) {
        Serial.write("# OK\n");
      } else {
        Serial.write("# FAIL\n");
      }
      cmdbufoff = 0;
    }
  }


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
