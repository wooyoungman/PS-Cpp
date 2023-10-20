-- 코드를 입력하세요

SELECT USER_ID,
        NICKNAME,
        CONCAT(CITY,' ', STREET_ADDRESS1,' ',STREET_ADDRESS2) AS '전체주소',
        CONCAT(SUBSTR(TLNO,1,3),'-',SUBSTR(TLNO,4,4),'-',SUBSTR(TLNO,8)) AS '전화번호'
FROM USED_GOODS_USER
-- 서브쿼리를 이용하여 USED_GOODS_BOARD 테이블에서 WRITER_ID를 그룹화 하고
-- HAVING 절의 COUNT 값이 3개 이상인 USER_ID 추출
WHERE USER_ID IN(
                    SELECT WRITER_ID
                    FROM USED_GOODS_BOARD
                    GROUP BY WRITER_ID
                    HAVING COUNT (*)>=3

)
ORDER BY USER_ID DESC