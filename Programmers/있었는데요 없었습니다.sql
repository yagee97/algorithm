SELECT a.ANIMAL_ID, a.NAME
FROM ANIMAL_INS a, ANIMAL_OUTS b 
WHERE a.DATETIME > b.DATETIME AND a.ANIMAL_ID = b.ANIMAL_ID
ORDER BY a.DATETIME ASC