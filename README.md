# RFID-Modul
RFID modul for å forsikre identifisering og sending av tidsinterval og id til server som tracker disse oversendelsene.

## TODO:

- [ ] Modul: Timer
 - [ ] Ha en timer som teller ned fra t0 til 0 og sender på serial
 - [ ] Koble mot stort display, kjøre timer på denne.
 - [ ] Test presisjon

- [ ] Modul: Send/Recieve
 - [ ] Etabler stabil kobling over antenne til PC
 - [ ] send ID og tidsinterval over antenne.
 - [ ] Sett timestamp
 - [ ] Test pålitlighet
 
- [ ] User friendliness
 - [ ] passe på at bruker ikke kan sende for ofte.
 - [ ] (optional) implementere komunikasjon på LCD skjerm

- [ ] Sever settup
 - [ ] Kjøre Send/Recieve på server
 - [ ] teste avstand

## LOG:
- [x] Kom igang med RFID
 - [x]  Registrere 8 sifret ID sende på COM
