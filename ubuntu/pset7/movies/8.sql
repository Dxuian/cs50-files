SELECT name from people where id IN 
( SELECT person_id from stars where
movie_id IN ( SELECT  id from movies where title = "Toy Story" )) ; 