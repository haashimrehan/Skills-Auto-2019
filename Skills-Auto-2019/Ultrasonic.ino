void readPing() {
  fPing = fPingSens.ping();
  fPing /= US_ROUNDTRIP_CM;
  Serial.println(fPing);
}
