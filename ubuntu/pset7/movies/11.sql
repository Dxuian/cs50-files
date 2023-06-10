-- -- select distinct title from movies where id in (select movie_id From stars where person_id in (select id From people where name= "Chadwick Boseman")) order by(select rating from ratings) limit 5 ;
--  /*order by (select rating from ratings where movie_id in (select id from movies where id in (select movie_id from stars where person_id in (select id from people where name = "Chadwick Boseman")))*/
-- select  title from movies join ratings on movies.id = ratings.movie_id where id in (select movie_id from stars where person_id in (select id from people where name = "Chadwick boseman"select
-- select title from movies where id in
-- (select movie_id from stars where person_id in
-- (select id from people where name= "Chadwick Boseman"))
-- order by (select rating from ratings where movie_id in
-- (select id from movies where id in
-- (select movie_id from stars where person_id in
-- (select id from people where name = "Chadwick Boseman")))) DESC limit 5 ;
select title from movies  inner join ratings on ratings.movie_id = movies.id where id in (select movie_id from stars where person_id in (select id from people where name = "Chadwick Boseman")) order by (rating) DESC limit 5 ; 










