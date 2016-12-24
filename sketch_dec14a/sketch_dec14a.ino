#include "FastLED.h"
// Number of LEDs on your light string
#define NUM_LEDS 50
// Which data pin on the Arduino is hooked up to the Data In wire on your light string
#define DATA_PIN 3
// For some reason, red and green were flipped on my lights. You might want to test these.
#define GREEN CRGB::Red
#define RED CRGB::Green
#define BLUE CRGB::Blue
#define BLACK CRGB::Black
#define WHITE CRGB::White
#define MAX_BRIGHTNESS 255

// This is the word that will be blinking, no spaces or special characters
char BLINK_WORD [] = "MERRYCHRISTMAS";

long randNumber;
// Pick a random color from this array
CRGB colors [4] = {RED, GREEN, BLUE, WHITE };
CRGB color;
CRGB leds[NUM_LEDS];

// Map characters to LED numbers, starting with index 0. 
// index 0 == 'A', 1 == 'B', etc
// Change these to match how your lights are actually hung
int characters [26] = {
  2, // A 
  3, // B
  4, // C
  5, // D
  7, // E
  8, // F
  10, // G
  11, // H
  29, // I
  28, // J
  26, // K
  25, // L
  24, // M
  23, // N
  21, // O
  20, // P
  19, // Q
  36, // R
  37, // S
  38, // T
  40, // U
  41, // V
  43, // W
  44, // X
  46, // Y
  47, // Z
};

// Map a lower case char to an LED
int charToLED(char c) {
  int i;
  if (c >= 97 && c <= 122) {
    // Lowercase
    i = c - 97;
  } else {
    // Uppercase
    i = c - 65;
  }

  return characters[i];
}

void initFlash() {
  // Flash every light as white 
  for ( int i = 0; i < NUM_LEDS; i = i + 1 ) {
    leds[i] = WHITE;
  }
  
  // Slowly go from off to full brightness
  for ( int j = 0; j < MAX_BRIGHTNESS; j = j + 1) {
    FastLED.setBrightness(j);
    delay(10);
    FastLED.show();
  }
  
  // Go from full brightness to off
  for ( int j = MAX_BRIGHTNESS; j >= 0; j = j - 1) {
    FastLED.setBrightness(j);
    delay(10);
    FastLED.show();
  }
  
  // Make the colored flashes full brightness
  FastLED.setBrightness(MAX_BRIGHTNESS);
  
  // Reset the LEDs to black so we can blink the word
  for ( int i = 0; i < NUM_LEDS; i = i + 1 ) {
    leds[i] = BLACK;
  }
  delay(3000);
}

// Flash a random color for each character
void blinkMessage() {
  int x, c;
  for ( int i = 0; i < sizeof(BLINK_WORD); i = i + 1 ) {
    color = colors[random(4)];
    c = BLINK_WORD[i];
    x = charToLED(c);
    leds[x] = color; FastLED.show(); delay(1000);
    leds[x] = BLACK; FastLED.show(); delay(800);
  }
  delay(2000);
}

// Run when the Arduino boots up. Set up FastLED
void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  randomSeed(analogRead(0));
}

// Run in a loop continuously
void loop() {
  initFlash();
  blinkMessage();
}
