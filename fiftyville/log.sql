-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year = 2021 AND day = 28;
--found out theft took place at 10.15am, 3 witnesses mentions bakery

SELECT activity,license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute = 14;
--found license plate entering right before theift

