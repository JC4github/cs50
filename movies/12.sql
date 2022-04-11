SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE EXISTS (SELECT id FROM people WHERE name = "Johnny Depp" OR name = "Helena Bonham Carter"));

SELECT title FROM movies WHERE id IN (SELECT movie_id FROM stars WHERE people_id IN (SELECT id FROM people WHERE name = "Johnny Depp" OR name = "Helena Bonham Carter"));