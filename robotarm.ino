

#include <SoftwareSerial.h>
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
SoftwareSerial Bluetooth(3, 4);
int s1p, s2p, s3p, s4p, s5p, s6p;
int s1pp, s2pp, s3pp, s4pp, s5pp, s6pp;
int s1sp[50], s2sp[50], s3sp[50], s4sp[50], s5sp[50], s6sp[50];
int speedDelay = 20;
int initial = 0;
String dataIn = "";
void setup() {
 servo1.attach(5);
 servo2.attach(6);
 servo3.attach(7);
 servo4.attach(9);
 servo5.attach(10);
 servo6.attach(11);
 Bluetooth.begin(9600);
 Bluetooth.setTimeout(1);
 delay(20);
 s1pp = 90;
 servo1.write(s1pp);
 s2pp = 150;
 servo2.write(s2pp);
 s3pp = 35;
 servo3.write(s3pp);
 s4pp = 140;
 servo4.write(s4pp);
 s5pp = 85;
 servo5.write(s5pp);
 s6pp = 80;
 servo6.write(s6pp);
}
void loop() {
 if (Bluetooth.available() > 0) {
 dataIn = Bluetooth.readString();


 if (dataIn.startsWith("s1")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s1p = dataInS.toInt();


 if (s1pp > s1p) {
 for ( int j = s1pp; j >= s1p; j--) {
 servo1.write(j);
 delay(20);
 }
 }

 if (s1pp < s1p) {
 for ( int j = s1pp; j <= s1p; j++) {
 servo1.write(j);
 delay(20);
 }
 }
 s1pp = s1p;
 }

 if (dataIn.startsWith("s2")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s2p = dataInS.toInt();
 if (s2pp > s2p) {
 for ( int j = s2pp; j >= s2p; j--) {
 servo2.write(j);
 delay(50);
 }
 }
 if (s2pp < s2p) {
 for ( int j = s2pp; j <= s2p; j++) {
 servo2.write(j);
 delay(50);
 }
 }
 s2pp = s2p;
 }

 if (dataIn.startsWith("s4")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s3p = dataInS.toInt();
 if (s3pp > s3p) {
 for ( int j = s3pp; j >= s3p; j--) {
 servo3.write(j);
 delay(30);
 }
 }
 if (s3pp < s3p) {
 for ( int j = s3pp; j <= s3p; j++) {
 servo3.write(j);
 delay(30);
 }
 }
 s3pp = s3p;
 }
 if (dataIn.startsWith("s5")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s4p = dataInS.toInt();
 if (s4pp > s4p) {
 for ( int j = s4pp; j >= s4p; j--) {
 servo4.write(j);
 delay(30);
 }
 }
 if (s4pp < s4p) {
 for ( int j = s4pp; j <= s4p; j++) {
 servo4.write(j);
 delay(30);
 }
 }
 s4pp = s4p;
 }
 if (dataIn.startsWith("s6")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s5p = dataInS.toInt();
 if (s5pp > s5p) {
 for ( int j = s5pp; j >= s5p; j--) {
 servo5.write(j);
 delay(100);
 }
 }
 if (s5pp < s5p) {
 for ( int j = s5pp; j <= s5p; j++) {
 servo5.write(j);
 delay(100);
 }
 }
 s5pp = s5p;
 }
 if (dataIn.startsWith("s7")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 s6p = dataInS.toInt();
 if (s6pp > s6p) {
 for ( int j = s6pp; j >= s6p; j--) {
 servo6.write(j);
 delay(30);
 }
 }
 if (s6pp < s6p) {
 for ( int j = s6pp; j <= s6p; j++) {
 servo6.write(j);
 delay(30);
 }
 }
 s6pp = s6p;
 }

 if (dataIn.startsWith("SAVE")) {
 s1sp[initial] = s1pp;
 s2sp[initial] = s2pp;
 s3sp[initial] = s3pp;
 s4sp[initial] = s4pp;
 s5sp[initial] = s5pp;
 s6sp[initial] = s6pp;
 initial++;
 }
 // If button "RUN" is pressed
 if (dataIn.startsWith("RUN")) {
 runservo();
 }
 // If button "RESET" is pressed
 if ( dataIn == "RESET") {
 memset(s1sp, 0, sizeof(s1sp));
 memset(s2sp, 0, sizeof(s2sp));
 memset(s3sp, 0, sizeof(s3sp));
 memset(s4sp, 0, sizeof(s4sp));
 memset(s5sp, 0, sizeof(s5sp));
 memset(s6sp, 0, sizeof(s6sp));
 initial = 0;
 }
 }
}
void runservo() {
 while (dataIn != "RESET") {
 for (int i = 0; i <= initial - 2; i++) {
 if (Bluetooth.available() > 0) {
 dataIn = Bluetooth.readString();
 if ( dataIn == "PAUSE") {
 while (dataIn != "RUN") {
 if (Bluetooth.available() > 0) {
 dataIn = Bluetooth.readString();
 if ( dataIn == "RESET") {
 break;
 }
 }
 }
 }

 if (dataIn.startsWith("ss")) {
 String dataInS = dataIn.substring(2, dataIn.length());
 speedDelay = dataInS.toInt();
 }
 }

 if (s1sp[i] == s1sp[i + 1]) {
 }
 if (s1sp[i] > s1sp[i + 1]) {
 for ( int j = s1sp[i]; j >= s1sp[i + 1]; j--) {
 servo1.write(j);
 delay(speedDelay);
 }
 }
 if (s1sp[i] < s1sp[i + 1]) {
 for ( int j = s1sp[i]; j <= s1sp[i + 1]; j++) {
 servo1.write(j);
 delay(speedDelay);
 }
 }
 if (s2sp[i] == s2sp[i + 1]) {
 }
 if (s2sp[i] > s2sp[i + 1]) {
 for ( int j = s2sp[i]; j >= s2sp[i + 1]; j--) {
 servo2.write(j);
 delay(speedDelay);
 }
 }
 if (s2sp[i] < s2sp[i + 1]) {
 for ( int j = s2sp[i]; j <= s2sp[i + 1]; j++) {
 servo2.write(j);
 delay(speedDelay);
 }
 }
 if (s3sp[i] == s3sp[i + 1]) {
 }
 if (s3sp[i] > s3sp[i + 1]) {
 for ( int j = s3sp[i]; j >= s3sp[i + 1]; j--) {
 servo3.write(j);
 delay(speedDelay);
 }
 }
 if (s3sp[i] < s3sp[i + 1]) {
 for ( int j = s3sp[i]; j <= s3sp[i + 1]; j++) {
 servo3.write(j);
 delay(speedDelay);
 }
 }
 if (s4sp[i] == s4sp[i + 1]) {
 }
 if (s4sp[i] > s4sp[i + 1]) {
 for ( int j = s4sp[i]; j >= s4sp[i + 1]; j--) {
 servo4.write(j);
 delay(speedDelay);
 }
 }
 if (s4sp[i] < s4sp[i + 1]) {
 for ( int j = s4sp[i]; j <= s4sp[i + 1]; j++) {
 servo4.write(j);
 delay(speedDelay);
 }
 }
 if (s5sp[i] == s5sp[i + 1]) {
 }
 if (s5sp[i] > s5sp[i + 1]) {
 for ( int j = s5sp[i]; j >= s5sp[i + 1]; j--) {
 servo5.write(j);
 delay(speedDelay);
 }
 }
 if (s5sp[i] < s5sp[i + 1]) {
 for ( int j = s5sp[i]; j <= s5sp[i + 1]; j++) {
 servo5.write(j);
 delay(speedDelay);
 }
 }
 if (s6sp[i] == s6sp[i + 1]) {
 }
 if (s6sp[i] > s6sp[i + 1]) {
 for ( int j = s6sp[i]; j >= s6sp[i + 1]; j--) {
 servo6.write(j);
 delay(speedDelay);
 }
 }
 if (s6sp[i] < s6sp[i + 1]) {
 for ( int j = s6sp[i]; j <= s6sp[i + 1]; j++) {
 servo6.write(j);
 delay(speedDelay);
 }
 }
 }
 }
}
