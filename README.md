# RFID-Modul
Første publisering

Mission 1 - Rask registrering
- Registrere 8 sifret ID

Mission 2 - Timestamp
- Synkronisere med global klokke
  Forslag: referansesendinger ved oppstart av RFID modul vil antageligvis kunne kalibrere klokka (CPU ticks) med global klokke
- Registrere timestamp
  steg 1: sende til COM
  steg 2: sende til COM med RFID

Mission 3 - Ship and share
- Lag array med nødvendig data, marshale (gjøre om til bit melding).
- Send data gjennom RF til annen pc

Mission 4 - Connect til Server
- Endre slik at data blir sendt gjennom RF til en server.


