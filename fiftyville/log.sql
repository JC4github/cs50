-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE year = 2021 AND day = 28;
--found out theft took place at 10.15am, 3 witnesses mentions bakery

SELECT activity,license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute = 14;
--found license plate entering right before theift

SELECT transcript FROM interviews WHERE year = 2021 AND day = 28 AND month = 7;
--10:05 - 10:25 thief left in a car
--thief withdow money at ATM on Leggett street

 SELECT activity,license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 5 AND 25 AND activity = "exit";
 --found all license plate of cars leaving at the time

 SELECT account_number, amount FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
 --look at withdaw on the day, found account numbers

 SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");
