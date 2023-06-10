-- -- -- -- -- -- -- -- -- -- Keep a log of any SQL queries you execute as you solve the mystery.
-- -- -- -- -- -- -- -- -- select * from crime_scene_reports ; 
-- -- -- -- -- -- -- -- -- --10:15 3 witnesses  ; 
-- -- -- -- -- -- -- -- select * from interviews where transcript like '%courthouse%'  and day >=28 ; 
-- -- -- -- -- -- -- /*161 | Ruth | 2020 | 7 | 28 | Sometime within ten minutes of the theft, I saw the th
-- -- -- -- -- -- -- ief get into a car in the courthouse parking lot and drive away. If you have security foota
-- -- -- -- -- -- -- ge from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
-- -- -- -- -- -- -- 162 | Eugene | 2020 | 7 | 28 | I don't know the thief's name, but it was someone I recognized.
-- -- -- -- -- -- -- Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street 
-- -- -- -- -- -- -- and saw the thief there withdrawing some money.
-- -- -- -- -- -- -- 163 | Raymond | 2020 | 7 | 28 | As the thief was leaving the courthouse, they called someone who 
-- -- -- -- -- -- -- talked to them for less than a minute. In the call, I heard the thief say that they were planning
-- -- -- -- -- -- -- \to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person 
-- -- -- -- -- -- -- on the other end of the phone to purchase the flight ticket.*/
-- -- -- -- -- -- -- select * from courthouse_security_logs where day = 28 and year = 2020 and month = 7 and hour  = 10 and minute between 15 and 25  ;
-- -- -- -- -- -- -- /*260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
-- -- -- -- -- -- -- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- -- -- -- -- -- -- 262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
-- -- -- -- -- -- -- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- -- -- -- -- -- -- 264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
-- -- -- -- -- -- -- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- -- -- -- -- -- -- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
-- -- -- -- -- -- -- 267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55*/
-- -- -- -- -- -- select * from atm_transactions where atm_location = "Fifer Street" and year=2020 and month = 7 and day = 28 and transaction_type =  "withdraw" ;
-- -- -- -- -- -- /*246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
-- -- -- -- -- -- 264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- -- -- -- -- -- 266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
-- -- -- -- -- -- 267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
-- -- -- -- -- -- 269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
-- -- -- -- -- -- 288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
-- -- -- -- -- -- 313 | 81061156 | 2020 | 7 | 28 | Fifer Street | withdraw | 30
-- -- -- -- -- -- 336 | 26013199 | 2020 | 7 | 28 | Fifer Street | withdraw | 35*/
-- -- -- -- -- select * from phone_calls where year = 2020 and month =  7 and day = 28 and duration <= 60 ; 
-- -- -- -- -- /*id | caller | receiver | year | month | day | duration
-- -- -- -- -- 221 | (130) 555-0289 | (996) 555-8899 | 2020 | 7 | 28 | 51
-- -- -- -- -- 224 | (499) 555-9472 | (892) 555-8872 | 2020 | 7 | 28 | 36
-- -- -- -- -- 233 |a (367) 555-5533 | (375) 555-8161 | 2020 | 7 | 28 | 45
-- -- -- -- -- 234 | (609) 555-5876 | (389) 555-5198 | 2020 | 7 | 28 | 60
-- -- -- -- -- 251 | (499) 555-9472 | (717) 555-1342 | 2020 | 7 | 28 | 50
-- -- -- -- -- 254 | (286) 555-6063 | (676) 555-6554 | 2020 | 7 | 28 | 43
-- -- -- -- -- 255 | (770) 555-1861 | (725) 555-3243 | 2020 | 7 | 28 | 49
-- -- -- -- -- 261 | (031) 555-6622 | (910) 555-3251 | 2020 | 7 | 28 | 38
-- -- -- -- -- 279 | (826) 555-1652 | (066) 555-9701 | 2020 | 7 | 28 | 55
-- -- -- -- -- 281 | (338) 555-6650 | (704) 555-2131 | 2020 | 7 | 28 | 54*/
-- -- -- -- select * from flights where day = 29 and year = 2020 and month = 7 and origin_airport_id = 8 order by hour  ; 
-- -- -- -- -- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20
-- -- -- select * from passengers where flight_id = 36   ; 
-- -- -- /*36 | 7214083635 | 2A
-- -- -- 36 | 1695452385 | 3B
-- -- -- 36 | 5773159633 | 4A
-- -- -- 36 | 1540955065 | 5C
-- -- -- 36 | 8294398571 | 6C
-- -- -- 36 | 1988161715 | 6D
-- -- -- 36 | 9878712108 | 7A
-- -- -- 36 | 8496433585 | 7B*/
-- -- -- select * from (select * from courthouse_security_logs where day = 28 and year = 2020 and month = 7 and hour  = 10 and minute between 15 and 25) where license_plate in (select license_plate from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year=2020 and month = 7 and day = 28 and transaction_type =  "withdraw"))) 
-- -- -- /*id | year | month | day | hour | minute | activity | license_plate
-- -- -- 261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
-- -- -- 263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
-- -- -- 265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
-- -- -- 266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE*/
-- -- select * from people where license_plate in (select license_plate from (select * from (select * from courthouse_security_logs where day = 28 and year = 2020 and month = 7 and hour  = 10 and minute between 15 and 25) where license_plate in (select license_plate from people where id in (select person_id from bank_accounts where account_number in (select account_number from atm_transactions where atm_location = "Fifer Street" and year=2020 and month = 7 and day = 28 and transaction_type =  "withdraw")))) where license_plate in  (select license_plate from people where phone_number in  (select caller from (select * from phone_calls where year = 2020 and month =  7 and day = 28 and duration <= 60 ) where caller in (select phone_number from people where passport_number in (select passport_number from passengers where flight_id = 36))))) ; 
-- select * from phone_calls where caller = "(367) 555-5533" and duration <=60 and day = 28 and year = 2020 ;
select * from people where phone_number =  "(375) 555-8161" ; 


