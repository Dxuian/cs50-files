-- -- -- select title from movies where id in (select movie_id from stars where person_id = (select id from people group by id having  name = "Johnny Depp" or name = "Helena Bonham Carter"))  ; 
-- -- select title from movies where id in ( select movie_id from stars where person_id in (select id from people ))
-- select * from (select title from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Helena Bonham Carter"))) as hel inner join 
--  (select title from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Johnny Depp")) ) as jo on hel.title = jo.title   ; 
-- SELECT *
-- FROM (select title from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Helena Bonham Carter"))) as he,
-- (select title from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Johnny Depp"))) as jo
-- WHERE he.title <> jo.title
-- AND he.title = jo.title
select title from  (select title as ho  from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Helena Bonham Carter"))) as he inner join (select title from movies where id in ( select movie_id from stars where person_id in (select id from people where name  = "Johnny Depp"))) as jo on he.ho =  jo.title  ; 