SELECT s.Score, (
    SELECT COUNT(*)
    FROM (
      SELECT DISTINCT Score
      FROM Scores i
        ) AS x
    WHERE x.Score >= s.Score
  ) AS Rank    
FROM Scores AS s
ORDER BY Score DESC;