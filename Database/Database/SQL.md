# SQL

- SQL 역사
    - SEQUEL에서 연유
        - 1974년 IBM 연구소에서 발표
        - IBM은 'SYSTEM R'의 인터페이스로 설계 및 구현되었다
            - 실험적 관계 데이터베이스 시스템의 인터페이스
    - SQL의 탄생 (Structured Query Language)
    - 표준 SQL
        - 1986년, SQL-86 or SQL 1
        - 1992년 개정, SQL/92, SQL-92 or SQL 2
        - 1999년 :  SQL3, SQL-99
        - 2003년 : SQL4, SQL-2003, 객체 개념을 지원하는 기능 추가
    - 현재
        - 미국 표준 연구소(ANSI)와 표준기구(ISO)에서 관계 데이터베이스의 표준언어로 채택
        - 상용 DBMS인 IBM의 DB2와 SQL/DS의 데이터 언어로 사용
        - ORACLE, INFORMIX, SYBASE등과 같은 모든 주요 제품에서 채택되었다
- SQL 특징
    - SQL(Structured Query Language)란
        - 구조화된 질의어
        - 종합 데이터베이스 언어 역할
            - 단순히 검색만을 위한 데이터 질의어가 아니다
        - 데이터 정의어(DDL), 데이터 조작어(DML), 데이터 제어어(DCL)의 기능을 모두 제공
    - 관계 대수 (Relational Algebra) + 확장된 투플 관계 해석 (Tuple Relational Calculus)에 기초
    - 고급, 비 절차적 데이터 언어
        - 사용자 친화적인 인터페이스를 제공한다
    - SQL의 표준화
        - 상용 RDBMS간의 전환이 용이하다
        - 여러 관계 데이터베이스를 접근하는 데이터베이스 응용 프로그램의 작성을 지원한다
    - 터미널을 통해 대화식 질의어로 사용
    - 응용 프로그램에 삽입된 형태로도 사용이 가능
        - Java, COBOL, C, C++ 등과 같은 범용 프로그래밍 언어로 된 응용 프로그램에서 사용 가능
    - 개개의 레코드 단위로 처리하기 보다는 레코드 집합 단위로 처리
    - 선언적 언어
        - SQL 명령문에는 데이터 처리를 위한 접근 경로에 대한 명세가 불필요
    
    <aside>
    💡 관계 모들의 공식 용어 대신 일반 용어를 사용한다
    Relation → Table, Tuple → Row, Attribute → Column
    
    </aside>
    
- SQL 데이터 정의문
    - 스키마와 카탈로그
        - Schema
            - 하나의 응용(User)에 속하는 테이블과 기타 구성요소 등의 그룹
            - 포함 내용 : 스키마 이름, 스키마를 소유하는 허가권자, 테이블, 뷰, 도메인, 기타내용에 대한 기술자
        - **CREATE SCHEMA** UNIVERSITY **AUTHORIZATION** YOON;
            - CREATE SCHEMA 대신 CREATE DATABASE 명령문 또한 사용 가능
            - DBA로부터 허가를 받은 사용자만 소유 할 수 있다
        - Catalog
            - SQL 시스템 내에 존재하는 스키마의 집합
            - 하나의 특별한 스키마인 Information_schema를 포함
                - 카탈로그에 있는 모든 스키마에 대한 정보를 제공한다
    - 도메인 정의문
        - 일반 형식
            - CREATE DOMAIN [도메인_이름] [데이터_타입] [기정 값_정의] [도메인_제약조건_정의리스트]
            
            ```sql
            CREATE DOMAIN DEPT CHAR(4) 
            DEFAULT '???' 
            CONSTRAINT VALID-DEPT 
            CHECK (VALUE IN 
            			('COMP', 'ME', 'EE', 'ARCH', '???'));
            ```
            
            - ALTER DOMAIN 도메인_이름 <변경 내용>
            - DROP DOMAIN 도메인_이름 RESTRICT | CASCADE;
                - RESTRICT : 다른 곳에서 이 도메인을 참조하고 있지 않을 때 삭제
                - CASCADE : 이 도메인을 참조하고 있는 뷰나 제약조건도 삭제
        - 데이터 타입
            - 숫자
                - INT, SMALLINT : 정수
                - FLOAT(n), REAL, DOUBLE PRECISION : 실수
                - DECIMAL(i, j), NUMERIC(i, j) : 정형 숫자
            - 문자 스트링
                - CHAR(n) : 고정 길이 문자
                - VARCHAR(n) : 가변 길이 문자
            - 비트 스트링
                - BIT(n), BIT VARYING(n)
            - 날짜
                - DATE : YY-MM-DD
            - 시간
                - TIME : hh:mm:ss
                - TIMESTAMP : DATE 와 TIME 포함
                - INTERVAL : DATE, TIME, TIMESTAMP 포함
    - 기본 테이블의 생성
        - 테이블의 종류
            - 기본 테이블 (base table)
                - CREATE TABLE 문으로 만들어지는 테이블
                - DBMS의 파일로 생성되고 저장
            - 가상 테이블 (virtual table)
                - CREATE VIEW 문으로 만들어지는 테이블
                - 어떤 기본 테이블로부터 유도되어 만들어지는 테이블
                - 독자적으로 존재 불가
            - 임시 테이블 (temporary table)
                - 질의문 처리 과정의 중간 결과로 만들어지는 테이블
                - DDL 문으로 만들어지는것이 아님
        - 일반형식
        
        ```sql
        CREATE TABLE 테이블 이름
        	({열이름 데이터타입 [NOT NULL][DEFAULT 값],}
        	[PRIMARY KEY (열이름_리스트),] #기본키와 개체 무결성 제약조건을 명세
        	{[UNIQUE (열이름_리스트),]}* #대체키를 명세 -> 후보키
        	{[FOREIGN KEY (열이름_리스트) #외래키와 참조 무결성 제약조건을 명세 
        														 #(참조된 테이블의 후보키도 외래키가 될 수 있음)
        	REFERENCES 기본테이블 [(열이름_리스트)]
        	[ON DELETE 옵션] #참조 투플이 삭제되면 옵션
        									#옵션에는 SET NULL, SET DEFAULT, CASCADE 존재
        		[ON UPDATE 옵션], ]}* #참조 투플이 갱신되면 갱신된 값이 파급적으로 갱신
        	[CONSTRAINT 이름][CHECK(조건식)]); #CHECK -> 제약조건
        ```
        
        ```sql
        CREATE TABLE ENROL
        	(Sno INTEGER NOT NULL,
        	Cno CHAR(6) NOT NULL,
        	Grade INTEGER,
        	PRIMARY KEY(Sno, Cno),
        	FOREIGN KEY(Sno) REFERENCES STUDENT(Sno)
        		ON DELETE CASCADE
        		ON UPDATE CASCADE,
        	FOREIGN KEY(Cno) REFERENCES COURSE
        		ON DELETE CASCADE
        		ON DELETE CASCADE,
        	CHECK(Grade >= 0 AND GRADE <= 100));
        ```
        
        - Create Table 시 무결성 제약조건
            - not null
            - primary key
            - foreign key references r
            
            ```sql
            create table instructor (
            	ID char(5),
            	name varchar(20) not null,
            	dept_name varchar(20),
            	salary numeric(8,2),
            	primary key (ID),
            	foreign key (dept_name) references department);
            ```
            
        - Relation Definitions
            
            ```sql
            create table student (
            	ID         varchar(5),
            	name       varchar(20) not null, 
            	dept_name  varchar(20)
            	tot_cred   numeric(3.0),
            	primary key (ID),
            	foreign key (dept_name) references department);
            ```
            
    - 기본 테이블의 제거와 변경
        - 기본 테이블의 제거
            - 일반 형식
                - DROP TABLE 기본_테이블_이름 {RESTRICT | CASCADE};
                - DROP TABLE COURSE CASCADE;
        - 스키마 제거
            - 일반 형식
                - DROP SCHEMA 스키마_이름 {RESTRICT | CASCADE};
                - DROP SCHEMA UNIVERSITY CASCADE;
        - 기본 테이블의 변경
            - 일반형식
                
                ```sql
                ALTER TABLE 기본_테이블_이름 
                	([ADD 열_이름 데이터_타입] [DEFAULT 기정 값] |
                	[DROP 열_이름] [CASCADE] |
                	[ALTER 열_이름 (DROP DEFAULT |
                								SET DEFAULT 기정 값)]);
                ```
                
            - 예시
                
                ```sql
                ALTER TABLE ENROL
                	ADD Final CHAR DEFAULT 'F';
                ALTER TABLE ENROL
                	DROP Grade CASCADE;
                ```
                
- SQL 데이터 조작문
    - 데이터 검색
        - 기본 구조
            
            ```sql
            SELECT 열_리스트 FROM 테이블_리스트 WHERE 조건;
            #예시#
            SELECT STUDENT.Sname, Student.Sno
            	FROM STUDENT
            	WHERE STUDENT.Dept = "Computer SC.";
            ```
            
        - 폐쇄 시스템 (Closed System / Closure Property)
            - 테이블 처리 결과가 또 다시 테이블이 되는 구조
            - 중첩 질의문을 구성 할 수 있는 이론적 기초가 된다
        - SQL과 이론적 relational model의 차이점
            - SQL의 테이블
                - 한 테이블 내에 똑같은 레코드(행) 중복 가능
                    - 기본키를 반드시 가져야 하는것이 아니다
                - 이론상 SQL의 테이블은 투플의 집합이 아니다
                - 같은 원소의 중복을 허용하는 다중집합(multiset) 또는 백(bag)
                    
                    → DISTINCT를 명세하면 집합과 같은 결과를 만들 수 있다
                    
    - 여러 형식의 데이터 검색
        - 일반적인 형식
            
            ```sql
            SELECT [ALL | DISTINCT] 열_리스트
            	FROM 테이블_리스트
            	[WHERE 조건]
            	[GROUP BY 열_리스트
            	[HAVING 조건]]
            	[ORDER BY 열_리스트 [ASC | DESC]];
            ```
            
        - 검색 결과에 레코드의 중복을 제거
            
            ```sql
            SELECT DISTINCT Dept
            	FROM STUDENT;
            ```
            
        - 테이블의 열 전부를 검색하는 경우
            
            ```sql
            SELECT *
            	FROM STUDENT;
            ```
            
        - 복수 테이블로부터의 검색 (조인)
            
            ```sql
            SELECT S.Sname, S.Dept, E.Grade
            	FROM STUDENT S, ENROL E
            	WHERE S.Sno = E.Sno AND E.Cno = 'C413';
            ```
            
        - 자기 자신의 테이블에 조인하는 검색
            - 같은 학과 학생의 학번을 쌍으로 검색. 첫번째 학번은 두번째 학번보다 작다
                
                ```sql
                SELECT S1.Sno, S2.Sno
                	FROM STUDENT S1, STUDENT S2
                	WHERE S1.Dept = S2.Dept
                		AND S1.Sno < S2.Sno;
                ```
                
        - FROM 절에 조인 명세
            
            ```sql
            SELECT Sname, Dept, Grade
            	FROM STUDENT JOIN ENROL ON
            		(STUDENT.Sno = ENROL.Sno)
            	WHERE EENROL.Cno = 'C413';
            
            SELECT Sname, Dept, Grade
            	FROM STUDENT JOIN ENROL USING(Sno)
            	WHERE ENROL.CNO = 'C413';
            
            SELECT Sname, Dept, Grade
            	FROM STUDENT NATURAL JOIN ENROL
            	WHERE ENROL.Cno = 'C413';
            ```
            
        - 집계 함수를 이용한 검색
            
            ```sql
            SELECT COUNT(*) AS 학생수
            	FROM STUDENT;
            
            SELECT COUNT(DISTINCT Cno)
            	FROM ENROL
            	WHERE Sno = 300;
            
            SELECT AVG(Midterm) AS 중간평균
            	FROM ENROL
            	WHERE Cno = 'C413';
            ```
            
        - GROUP BY를 이용한 검색
            
            ```sql
            SELECT Cno, AVG(FINAL) AS 기말평균
            	FROM ENROL
            	GROUP BY Cno;
            ```
            
        - HAVING을 사용한 검색
            
            ```sql
            SELECT Cno, AVG(Final) AS 평균
            	FROM ENROL
            	GROUP BY Cno
            	HAVING COUNT(*) >= 3;
            ```
            
        - 부속 질의문을 사용한 검색
            - 부속 질의문이란
                - 다른 질의문에 중첩되어 사용된 검색문
                - 형태 : SELECT-FROM-WHERE-GROUP BY-HAVING
                - 중첩 질의문 : 부속 질의문을 포함하고 있는 질의문
                - IN 다음에 사용 : 집합의 멤버십 연산자로 해석
            
            ```sql
            SELECT Sname
            	FROM STUDENT
            	WHERE Sno IN
            		(SELECT Sno
            		FROM ENROL
            		WHERE Cno = 'C413');
            
            SELECT Sname, Dept
            	FROM STUDENT
            	WHERE Dept = 
            		(SELECT Dept
            		FROM STUDENT
            		WHERE Sname = 'YeongGi');
            
            #학번이 500인 학생의 모든 기말 성적보다 좋은 학기말 성적을 받은 학생의
            #학번과 과목번호를 검색
            SELECT Sno, Cno
            	FROM ENROL
            	WHERE Final > ALL
            		(SELECT Final
            		FROM ENROL
            		WHERE Sno = 500);
            ```
            
        - LIKE를 사용하는 검색
            - LIKE → 서브 스트링 패턴 비교 연산자
            - % → 어떤 길이의 어떤 문자 스트링도 상관 없음
            - _ → 문자 하나를 의미
            
            ```sql
            SELECT Cno, Cname
            	FROM COURSE
            	WHERE Cno LIKE 'C%';
            ```
            
        - NULL을 사용한 검색
            - 누락된 정보 → missing information
            - 값은 있지만 모르는 값 → unknown value
            - 해당되지 않는 값 → unapplicable value
            - 의도적으로 유보한 값 → withheld value
            
            ```sql
            SELECT Sno, Sname
            	FROM STUDENT
            	WHERE Dept IS NULL;
            #'열_이름 IS [NOT] NULL' 의 형식만 제공된다. '열_이름 = NULL'은 불법
            ```
            
        - EXISTS를 사용하는 검색
            
            ```sql
            SELECT Sname
            	FROM STUDENT
            	WHERE EXISTS
            		(SELECT *
            		FROM ENROL
            		WHERE Sno = STUDENT.Sno
            			AND Cno = 'C413');
            ```
            
            <aside>
            💡 EXISTS 이하 SELECT문이 참 일 때 본 SELECT를 실행한다
            
            </aside>
            
        - UNION이 관련된 검색
            
            ```sql
            SELECT Sno
            	FROM STUDENT
            	WHERE Year = 1
            		UNION
            	SELECT Sno
            		FROM ENROL
            		WHERE Cno = 'C324';
            ```
            
            <aside>
            💡 합칩합의 연산으로, 중복된 투플은 제거된다
            
            </aside>
            
    - 데이터의 갱신
        - 일반적인 형식
            
            ```sql
            UPDATE 테이블
            	SET { 열_이름 = 산술식}
            	[WHERE 조건];
            ```
            
        - 하나의 레코드 변경
            
            ```sql
            UPDATE STUDENT
            	SET Year = 2
            	WHERE Sno = 300;
            ```
            
        - 복수의 레코드 변경
            
            ```sql
            UPDATE COURSE
            	SET Credit = Credit + 1
            	WHERE Dept = 'Comp Sci.';
            ```
            
        - 부속 질의문을 이용한 변경
            
            ```sql
            UPDATE ENROL
            	SET Final = Final + 5
            	Where Sno IN
            		(SELECT Sno
            		FROM STUDENT
            		WHERE Dept = 'Comp Sci.');
            
            UPDATE STUDENT
            	SET Dept = 
            		(SELECT Dept
            		FROM COURSE
            		WHERE Cname = 'Database')
            	WHERE Year = 4;
            ```
            
    - 데이터의 삽입
        - 일반형식
            
            ```sql
            INSERT
            	INTO 테이블 [열_이름_리스트]
            	VALUES (열값_리스트);
            
            INSERT
            	INTO 테이블 [열_이름_리스트]
            	SELECT 문;
            ```
            
        - 레코드의 직접 삽입
            
            ```sql
            INSERT
            	INTO STUDENT(Sno, Sname, Year, Dept)
            	VALUES (600, 'Yoon YeongGi', 3, 'Comp Sci.');
            ```
            
        - 부속 질의문을 이용한 레코드 삽입
            
            ```sql
            INSERT
            	INTO STUDENT(Sno, Sname, Year)
            	SELECT Sno, Sname, Year
            	FROM STUDENT
            	WHERE Dept = 'Comp Sci.';
            ```
            
    - 데이터의 삭제
        - 일반 형식
            
            ```sql
            DELETE
            	FROM 테이블
            	[WHERE 조건];
            ```
            
        - 하나의 레코드 삭제
            
            ```sql
            DELETE
            	FROM STUDENT
            	WHERE Sno = 100;
            ```
            
            <aside>
            💡 참조 무결성 문제에 주의
            
            </aside>
            
        - 복수의 레코드 삭제
            
            ```sql
            DELETE
            	FROM ENROL;
            ```
            
        - 복수 질의문을 이용한 삭제
            
            ```sql
            DELETE
            	FROM ENROL
            	WHERE Cno = 'C413' AND Final < 60
            		AND ENROL>Sno IN
            			(SELECT Sno
            			FROM STUDENT
            			WHERE Dept = 'Comp Sci.');
            ```
            
    - Joined Tables
        - Join Operation은 두 relation을 가지고 하나의 relation을 리턴해 준다
        - 보통 from clause에서 추가로 사용된다
    - some 과 all clause
        
        some
        
        ![Untitled](SQL%205679da08001141ba817d3eb0a797fc2b/Untitled.png)
        
        all
        
        ![Untitled](SQL%205679da08001141ba817d3eb0a797fc2b/Untitled%201.png)
        
- SQL View
    - 하나 또는 둘 이상의 기본 테이블로부터 유도되어 만들어지는 가상의 테이블
    - 외부 스키마는 뷰와 기본 테이블들의 정의로 구성된다
    - 기본 테이블을 들여다보는 '유리창' → 동적으로 작동한다
    - 물리적인 구현이 아닌, 뷰의 정의만 카탈로그되어 SELECT-FROM-WHERE 형태로 저장
    - 뷰에 대한 내용 변경 → 테이블에 대한 변경
    - 뷰의 생성
        
        ```sql
        CREATE VIEW 뷰_이름[(열_이름리스트)]
        	AS SELECT문
        	[WITH CHECK OPTION];
        
        CREATE VIEW CSTUDENT(Sno, Sname, Year)
        	AS SELECT Sno, Sname, Year #열의 이름 상속
        	FROM STUDENT
        	WHERE Dept = 'Comp Sci.'
        	WITH CHECK OPTION;
        ```
        
        두개 이상 테이블을 조인
        
        ```sql
        CREATE VIEW HONOR(Sname, Dept, Grade)
        	AS SELECT STUDENT.Sname, STUDENT.Dept, ENROL.Final
        	FROM STUDENT, ENROL
        	WHERE STUDENT.Sno = ENROL.Sno
        		AND ENROL.Final > 90;
        ```
        
        정의된 뷰를 이용하여 다른 뷰를 정의
        
        ```sql
        CREATE VIEW COMHONOR
        	AS SELECT Sname
        	FROM HONOR
        	WHERE Dept = 'Comp Sci.';
        ```
        
    - 뷰의 제거
        
        DROP VIEW 뷰_이름 {RESTRICT | CASCADE};
        
    - 뷰의 조작연산
        - 기본 테이블에 사용 가능한 검색문은 모두 뷰에 사용 가능하다
        - 변경 연산은 제약이 있다
            - 열 부분 집합의 뷰
                - 기본 키 포함 → 삽입, 제거, 갱신 가능
                - 기본 키 불포함 → 삽입, 삭제, 갱신 불가능
            - 행 부분 집합
                - 이론적으로 삽입, 삭제, 갱신 가능 (null 발생, uniqueness 문제가 있다)
            - 조인 뷰
                - 삽입, 삭제, 갱신 불가
            - 통계적 요약 뷰
                - 삽입, 삭제, 갱신 불가
        - 변경 연산이 허용되지 않는 경우
            - 뷰의 열이 상수나 산술 연산자 또는 함수가 사용된 산술식 일 경우
            - 집계 함수가 관련되어 정의 된 경우
            - DISTINCT, GROUP BY, HAVING이 사용되어 정의된 경우
            - 두개 이상의 테이블이 관련되어 정의 된 경우
            - 변경할 수 없는 뷰를 기초로 정의 된 경우
        - 뷰의 장단점
            - 장점
                - 논리적 독립성을 제공
                - 데이터의 접근을 제어
                - 사용자의 데이터 관리를 단순화
                - 여러 사용자에게 다양한 데이터 요구를 지원
            - 단점
                - 정의를 변경 할 수 없음
                - 삽입, 삭제, 갱신 연산에 제한이 많다
- 삽입 SQL
    - SQL의 이중모드 원리
        - 터미널에서 대화식으로 사용 할 수 있는 모든 SQL문 → 응용 프로그램에서 사용가능
    - 삽입 SQL을 포함하는 응용 프로그램의 특징
        - 명령문 앞에 EXEC SQL을 붙인다
        - 삽입 SQL 실행문은 호스트 실행문이 나타나는 어느곳에서 사용 가능
        - 호스트 변수는 콜론(:)을 앞에 붙인다
        - 호스트 변수 SQLSTATE를 포함
            - 피드백 정보를 제공
            - SQLSTATE = '00000' : 성공 (아니면 경고 or error)
        - 호스트 변수와 대응하는 열의 데이터 타입은 일치
        - 호스트 변수와 열의 이름은 같을 수 있다
        - SQLSTATE 변수에 반환된 값을 조건으로 사용
- Dynamic SQL
    - 온라인 응용
        - 터미널로 데이터베이스 접근을 지원하는 응용 프로그램 → dynamic SQL로 구성
    - 온라인 응용의 수행 과정
        - 터미널에서 명령문을 접수
        - 입력된 명령문을 분석
        - 데이터베이스에 적절한 SQL문으로 지시
        - 터미널에 메시지나 결과를 반환
    - 기본 명령어
        - PREPARE
            - SQL문을 컴파일 해 object coede로 생성하여 저장
        - EXECUTE
            - 저장되어 있는 object code의 SQL문을 실행
        - 목적 코드로 변환시키는 PREPARE 문에는 모든 종류의 SQL문 포함 가능