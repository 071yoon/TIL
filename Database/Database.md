# Database

[Database Concepts ,JUNGIK PUBLISHING CO.] 참조

- Database의 기본 개념
    - What is Database?
        
        한 조직의 여러 응용 시스템들이 공용하기 위해 통합, 저장한 운영 데이터의 집합
        
        - 공용 데이터
            - 한 조직의 여러 응용 시스템들이 공동으로 소유, 유지, 이용하는 데이터
        - 통합 데이터
            - 최소의 중복
            - 통제된 중복
        - 저장 데이터
            - 컴퓨터가 접근 가능한 매체이 저장
            - 디스크, 테이프 etc.
        - 운영 데이터
            - 한 조직의 고유 기능을 수행하기 위해 필요한 데이터
    - Database의 특성
        - 실시간 접근성
            - 질의에 대한 실시간 처리 및 응답
        - 계속적인 변화
            - 갱신, 삽입, 삭제, 동적인 특성으 가진다
        - 동시 공용
            - 여러 사용자가 동시에 사용 할 수 있음
        - 내용에 의한 참조
            - 데이터의 위치 혹은 주소가 아닌 내용에 의해 참조 가능
    - Database의 구성요소
        - 물리적 구성요소 vs 논리적 구성요소
            - bit, byte, block, cylinder  등의 저장장치의 물리적 요소
            - 사용자의 입장에서 → 구성요소
            - 데이터베이스 = { 개체, 관계}
        - 개체란
            - 표현하려는 유무형 정보의 객체로 구별
            - 사용자 관점의 정보의 단위
            - 하나 이상의 속성으로 구성
                - 데이터의 가장 작은 논리적 단위
            - 개체 집합
                - entity type vs. entity instance/ entity occurence
            - 일반 레코드와 대응
                - record type vs. record instance/ record occurence
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled.png)
            
        - 관계란
            - 속성 관계
                - 개체 내 관계 : 특성
            - 개체 관계
                - 개체 간 관계
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%201.png)
            
    - Database의 구조
        - 논리적 구조
            - 사용자의 관점에서 본 데이터의 개념적 구조
            - 데이터의 논리적 배치 → 가상적 구조
            - 논리적 레코드
        - 물리적 구조
            - 저장 관점에서 본 데이터의 물리적 배치
            - 저장장치에 저장된 데이터의 실제 구조
            - 추가 정보를 포함한다
                - index, pointer chain, overflow area etc.
            - 저장 레코드
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%202.png)
        
    - DBMS의 발전 배경
        
        ### 발전배경 1
        
        - 데이터베이스 관리 시스템
        - 파일 중심 데이터 처리 시스템이 지원 file system → operating system
            - 각 응용 프로그램이 논리적 파일 구조를 정의하고 직접 물리적 파일 구조로 구현
            - 각 응용 프로그램이 물리적 데이터 구조에 대한 접근 방법을 구현
            - 각 사용자가 데이터와 이를 처리하는 프로그램을 모두 관리 유지
            - 응용 간의 데이터 공용이 불가능
        - 데이터 종속성과 중복성을 야기한다
        
        ### 발전배경 2
        
        - 파일 시스템에서 응용프로그램과 파일과의 관계
            - 1:1의 관계
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%203.png)
            
        
        ### 발전배경 3
        
        - 데이터 종속성
            - 응용 프로그램과 데이터간의 산호 의존관계
            - 데이터의 구성방법이나 접근방법의 변경 시 관련 응용 프로그램도 동시에 변경해야된다
            - 응용 프로그램의 관리가 어렵다
        - 데이터 중복성
            - 한 시스템 내에 같은 내용의 데이터가 여러 파일에 중복 저장되어 관리
            - 문제점
                - 일관성
                - 보안성
                - 경제성
                - 무결성
        
        ### 발전배경 4
        
        - 파일 관리 시스템과 응용 프로그램
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%204.png)
        
    - 데이터베이스 관리 시스템의 정의
        - DBMS(Database management system) 이란?
            
            응용 프로그램과 데이터 사이의 중재자로 모든 응용 프로그램들이 데이터베이스를 공용되게 사용 할 수 있게 관리해 주는 범용 소프트웨어 시스템
            
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%205.png)
        
    - DBMS의 필수기능
        
        ### 1. 정의 기능
        
        - 하나의 저장 구조로 여러 사용자의 요구를 지원할 수 있도록 데이터를 조직화 하는 기능
        - 정의 기능의 요구조건
            - 데이터의 논리적 구조를 명세
            - 데이터의 물리적 구조를 명세
            - 물리적/논리적 사상(mapping)을 명세
        
        ### 2. 조작 기능
        
        - 사용자와 데이터베이스 간의 interface를 위한 수단
        - 체계적 데이터베이스 접근 및 조작: 검색, 갱신, 삽입, 삭제
        - 데이터 언어로 표현
            - 사용하기가 쉽고 자연스러운 도구
            - 명확하고 완전 → 원하는 연산의 명세 가능
            - 효율적인 처리
        
        ### 3. 제어 기능
        
        - 데이터의 정확성과 안전성을 유지하는 기능
        - 제어기능의 요구조건
            - 무결성 유지
            - 보안, 권한 검사
            - 병행수행의 제어
            - 복구
    - DBMS의 장단점
        - 장점
            - 데이터 중복의 최소화
            - 데이터의 공용
            - 데이터의 독립성 확보
            - 일관성 유지
            - 무결성 유지
            - 보안 보장
            - 표준화에 용이
            - 기관 전체 데이터 요구의 조정
            - 장애발생 시 회복에 용이
        - 단점
            - 유지비의 overhead 발생
            - 특정 응용 프로그램의 복잡화
            - 복잡한 backup과 recovery
            - 중앙 관리 시스템의 취약성
    - DBMS의 궁극적 목적
        - DBMS의 궁극적 목적은 데이터의 독립성
            - 논리적 데이터 독립성
                - 응용 프로그램에 영향을 주지 않고 논리적 데이터 구조의 변경이 가능
                - 응용 프로그램의 효율적 개발이 가능
            - 물리적 데이터 독립성
                - 응용 프로그램과 논리적 데이트 구조에 영향을 주지 않고 물리적 데이트 구조의 변경이 가능
                - 저장 장치의 효율적 개발이 가능
        - 데이터 독립성 구현 기법
            - 사상(mapping)
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%206.png)
        
    - DBMS의 발전 과정
        - 제 1세대 DBMS
            - IDS(Integrated Data Store)
                - 최초의 범용 DBMS
                - 1960년대 초 General Electric의 Charles Bachman에 의해 설계
                - 네트워크 데이터 모델(network data model)의 기초
                - Bachman은 또한 데이터 구조도또한 제한
            - IMS(Information Management System) DBMS
                - 1960년대 후반 IBM이 개발
                - 계층 데이터 모델의 기초
                - 1970년대초에 대형 컴퓨터 회사들이 DBMS를 자체 제작 판매
        - 제 2세대 DBMS
            - 관계 데이터 모델
                - IBM의 E.F.Codd의 제안
                - Relational Database 이론의 기초
                - 1980년대 DBMS의 주류로 확장
            - SQL
                - IBM이 관계 DBMS의 일부로 개발
                - 세계 표준 데이터베이스 언어
            - 주요 상용 DBMS
                - DB2, Oracle, MS SQL, Sybase, Informix
            - PC 기반 DBMS
                - Access, FoxPro, DBase, Paradox
        - 제 3세대 DBMS
            - 사용자의 데이터베이스 응용에 대한 복잡성 증대
                - engineering, iamges, videos, spatial, time series, data mining
            - 사용자의 요구에 대처하기 위해 새로운 data model을 기반으로 시스템 개발
                - 객체지향 DBMS
                - Object-oriented programming-base
                - O2, ONTOS, GemStone etc.
            - 현재는 제2세대 DBMS + 제 3세대 DBMS
                - 객체 관계 DBMS → Object-Relational DBMS
        - 제 4세대 DBMS
            - NoSQL : 비정형 데이터 처리, 뛰어난 확장성
                - 안정성과 일관성 유지 포기
                - 데이터 구조를 미리 정하지 않아 유연함
                - 뛰어난 확장성으로 데이터의 분산 처리에 적합
                - 몽고DB, Hbase, Cassandra, Redia, Neo4j, OrientDB etc.
            - NewSQL DBMS
                - 관계  DBMS + NoSQL
                - 구글 Spanner, VoltDB, NuoDB etc.
    - Database 시스템
        
        Database system 이란 : 데이터를 데이터베이스로 저장 관리하여 정보를 생성하는 컴퓨터 중심 시스템
        
        - 구성요소
            - 3-Level Database
            - Data Languages
            - Users
            - DBMS
            - Database Administrator
            - Databse Computer (H/W)
    - 3단계 데이터베이스 (스키마의 표현)
        - Database의 3단계
            - DB의 3단계 표현
                - DB에 대한 3단계 관점 → (개인, 기관 전체, 저장장치)
                    - 외부 단계
                    - 개념 단계
                    - 내부 단계
            - 스키마
                - DB의 논리적 정의
                    - 구조(개체, 속성, 관계)와 제약조건을 명세
                - 관점에 따른 3단계 DB구조에 기반
                    - 외부 스키마 (external schema) → subschema
                        - 개개 사용자 관점에서 정의한 DB 스키마
                        - 다수의 응용/ 사용자가 사용하는 전체 DB의 한 논리적 부분
                    - 개념 스키마 (conceptual schema) → schema
                        - 범 기관적인 관점에서 정의한 DB 스키마
                        - 모든 응용에 대한 전체적인 통합된 데이터 구조
                        - 모든 외부 스키마의 출발점
                    - 내부 스키마
                        - 저장장치 관점에서 정의한 DB 스키마
                        - 개념 스키마에 대한 저장구조를 정의
                            - 레코드 형식, 인덱스의 유무, 데이터의 표현방법, 레코드의 물리적 순서 etc
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%207.png)
            
        - 3단계간의 사상(Mapping)
            - 외부/ 개념 단계 간의 매핑
                - 외부 스키마와 개념 스키마 간의 대응 관계를 정의
                - 응용 인터페이스
                - 논리적 데이터 독립성을 제공
            - 개념/ 내부 단계 간의 매핑
                - 개념 스키마와 내부 스키마 간의 대응 관계를 정의
                - 저장 인터페이스
                - 물리적 데이터 독립성을 제공
            
            - 스키마는 컴파일 되어 catalog에 저장되며 스키마를 그래픽 형태로 표현한 것이 스키마 다이어그램이 된다.
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%208.png)
            
        - System Catalog & Data Directory
            - System Catalog
                - 시스템 내의 모든 객체들에 대한 정의나 명세에 대한 정보
                - 시스템 DB, 메타 데이터베이스
                - DB 관리자 → DBA 가 사용하는 도구
                - 사용자와 시스템 모두 사용
                - 데이터 사전이라고도 불린다
            - Data Directory
                - DB에 저장된 데이터를 참조 하는데 필요한 정보들을 수록
                - 시스템만 사용한다
    - 데이터 언어 (Data Language)
        
        **데이터베이스를 정의, 조작, 제어 하기 위한 시스템과의 통신수단**
        
        - 데이터 정의어
            
            DDL : Data Definition Language
            
            → 데이터베이스 구조를 정의하고 변경하는데 사용
            
            - 데이터 정의의 내용
                - 논리적 데이터 구조의 정의
                    - 스키마, 외부 스키마 명세
                - 물리적 데이터 구조의 정의
                    - 내부 스키마 명세
                    - 데이터 저장 정의어
                - 논리적 데이터 구조와 물리적 데이터 구조 간의 사상을 정의
        - 데이터 조작어
            
            DML : Data Manipulation Language
            
            → 사용자와 DBMS 사이의 통신수단으로 데이터 처리 연산의 집합 (검색, 삽입, 삭제, 변경)
            
            - 절차적 DML
                - 저급 데이터 언어
                - what과 how를 명세
                - 한번에 하나의 레코드만 처리
                - 응용 프로그램 속에 삽입 되어 사용된다
                - DML 예비 컴파일러에 의해 처리
            - 비절차적 DML
                - 고급 데이터 언어
                - what 만 명세 후 how 는 시스템에 위임
                - 한번에 여러 개의 레코드를 처리
                - 질의어(Query)
                    - 독자적이고 대화식 : command type
                    - 프로그램의 추상적인 표현
                
                Else
                
                - 데이터 부속어 : DSL (Data Sublanguage)
                    - host program 속에 삽입되어 사용하는 DML
                    - 비절차적 or 절차적 DML
                - 데이터 언어의 완전성
                    - 사용자가 원하면 어떤 객체도 추출 및 관계 표현을 할 수 있는 능력
        - 데이터 제어어
            
            DCL : Data Control Language
            
            - 공용 데이터베이스 관리를 위해 데이터 제어를 정의하고 기술
            - 데이터 제어 내용
                - 데이터 보안
                - 데이터 무결성
                - 데이터 회복
                - 병행수행
            - DB 관리 목적으로 DBA가 사용
    - 사용자 (Users)
        - 일반 사용자
            - 비절차적 DML을 통해 데이터베이스를 접근
            - menu, form, graphics
            - 데이터의 삽입, 삭제, 갱신, 검색
        - 응용 프로그래머
            - 응용 프로그램을 통해 DB에 접근
            - host 언어: PL/I, COBOL, PASCAL, C, JAVA
        - DB 관리자 → DBA
            - DDL과 DCL을 통해 DB를 정의하고 제어
    - DBMS
        
        DBMS는 Database를 관리하고 사용자가 요구하는 모든 연산을 수행
        
        1. 사용자의 접근요구를 접수 및 분석
        2. 시스템이 이해할 수 있는 형태로 사요자 요구를 변환
        3. 외부/개념/내부/저장 구조간의 매핑을 수행하여 저장 데이터를 접근
        4. 저장 DB에 필요한 연산을 실행
        - DBMS의 구성요소
            - DDL 컴파일러
                - DDL로 명세된 schema를 내부 형태로 변환하여 catalog에 저장
                - 메타 데이터베이스 : 데이터의 데이터
            - 질의어 처리기
                - 질의문을 쪼개고 분석 컴파일 하여 DB에 접근하기 위한 object code를 생성
            - 예비 컴파일러
                - 응용 프로그램에 삽입된 DML을 추출하고 그 자리에 procedure call로 대체
                - 추출된 DML은 다시 DML 컴파일러로 전달
                - 수정된 응용 프로그램은 host 프로그램 컴파일러로 전달
            - DML 컴파일러
                - DML 명령어를 object code 로 변환
            - 런타임 데이터베이스 처리기
                - 실행 시간에 데이터베이스를 접근
                - DB 연산을 저장 데이터 관리자를 통해 수행
            - 트랜잭션 관리자
                - 트랜잭션 단위로 작업을 수행
                - DB 접근 과정에서 무결성과 권한 제어
                - 병행제어와 회복 작업
            - 저장 데이터 관리자
                - 디스크에 있는 사용자 DB나 카탈로그 접근을 제어
                - 기본 OS module을 이용한다
                    - file manager가 파일의 페이지 결정
                    - disk manager가 데이터 전송을 수행
                    - 메모리 내에 buffer manager 가 관리
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%209.png)
            
    - 데이터베이스 관리자(DBA)
        
        DBA : Database Adminstrator는 DB의 시스템 관리, 운영에 대한 모든 책임을 진다
        
        - DBA의 대표 업무
            - DB 설계와 운영
                - DB의 구성요소를 결정 (개체, 속성, 관계)
                - 스키마의 정의
                - 저장 구조와 접근 방법 설정
                - 보안 정책 수립, 권한부여, 유효성 검사
                - 백업, 회복 절차의 수립
                - DB의 무결성 유지
                - 성능 향상과 새로운 요구에 대응한 DB의 재구성
                - 시스템 Catalog의 유지 관리
            - 행정 및 불평 해결
                - 데이터의 표현과 시스템의 문서화에 표준을 설정
                - 사용자의 요구 및 불평 해결
            - 시스템 감시 및 성능 분석
                - 시스템 성능의 청취
                - 자원의 이용도, 병목현상, 장비성능 등
                - 사용자 요구의 변화, 데이터 사용 추세, 각종 통계의 종합 분석
    - 하드웨어 → 데이터베이스 컴퓨터
        - 대규모 Database (VLDB)
            - GB-gigabyte : 1024MB
            - TB-terabyte : 1024GB
            - PB-petabyte : 1024TB
            - EB-exabyte : 1024PB
        - DB 기능만을 효율적으로 수행하기 위한 특수 목적의 하드웨어
            - backend computer
            - 지능형 저장장치
            - 내용식 메모리 (associative memory)
            - 병렬처리
    
    ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2010.png)
    
- 관계 데이터베이스
    - 관계 데이터 모델이란
        
        1970년 IBM의 E. F. Codd에 의해 관계 데이터 모델이 탄생
        
        - 관계 데이터 모델의 특성
            - 수학에서의 relation 과 set 이론에서 기초
            - 일반 사용자 기준 table 의 형태이다
                - 통상적인 테이블과는 사뭇 다름
                - table의 colum → field/item 이 관계 데이터 모델의 attribute 속성
                - table의 row → record 가 관계 데이터 모델의 tuple 객체
        
        ex) 학생 테이블 : relation
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2011.png)
        
    - Attribute & Domain
        - table 은 relation과 유사하다
        - domain
            - attribute가 취할 수 있는 값들의 집합
        - attribute
            - domain의 역할의 이름
            - 한 relation 내에서 attribute의 이름들은 모두 달라야 한다
        - 단순 도메인
            
            → 단순 애트리뷰트 : 원자값
            
        - 복합 도메인
            
            → 복합 애트리뷰트 : 복합값 ex) 날짜:<년,월,일>
            
        
        <aside>
        💡 애트리뷰트 이름과 도메인 이름은 같을 수 있다
        
        </aside>
        
    - Relation
        - 예시 → **Student Relation 정의**
            
            ```sql
            DCL DOMAIN DSNO INTEGER; 
            DCL DOMAIN NAME CHAR(10); 
            DCL DOMAIN DYEAR INTEGER; 
            DCL DOMAIN DEPT CHAR(6); 
            DCL RELATION STUDENT
            	(Sno DOMAIN DSNO, 
            	Sname DOMAIN NAME, 
            	Year DOMAIN DYEAR, 
            	Dept DOMAIN DEPT);
            ```
            
            도메인 생략시 Student Relation
            
            ```sql
            DCL RELATION STUDENT
            	(Sno INTEGER,
            	Sname CHAR(10), 
            	Year INTEGER,
            	Dept CHAR(6));
            ```
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2012.png)
            
        - Relation Schema
            - 릴레이션 내포(intension) or 릴레이션 스킴이라 한다
                - 릴레이션 이름 + 애트리뷰트 이름
            - 정적 성질을 띈다
                - 시간에 무관
                - 릴레이션 타입과 같은 의미이다
        - Relation Instance
            - 릴레이션 외연(extension) 이라 한다.
            - Relation R의 인스턴스
                - 어느 한 시점에 릴레이션 R이 포함하고 있는 투플들의 집합
                - 릴레이션의 내용, 상태, snapshot
            - 투플 : {(attr1 = V1, attr2 = V2, ''', attrn = Vn)}
            - 동적 성질
                - 삽입, 삭제 갱신으로 시간에 따라 변한다
                - 릴레이션의 값
        - Relation R
            - 수학적 정의
                - 카티션 프로덕트의 부분집합
                - 투플의 수 : 카디널리티
            - 개념적 정의
                - 릴레이션 스키마 + 릴레이션 인스턴스
    - Relation의 특성
        - 투플의 유일성
            - 릴레이션 = 투플들의 집합
        - 투플의 무순서성
            - 릴레이션 : 추상적 개념 ≤ 투플들의 집합
            - 테이블 : 구체적 개념
        - 애트리뷰트의 무순수성
            - 릴레이션 스티마 → 애트리뷰트들의 집합
            - 투플 쌍들의 집합
        - 애트리뷰트의 원자성
            - 애트리뷰트 값은 원자 값 → 분해 불가능
            - 정규화 릴레이션
                - 애트리뷰트 값으로 원자값만 허용됨
                - 비정규화 릴레이션은 분해를 통해 정규화
                - 동등한 의미를 유지한다
            - 널값 또한 원자값
            - 도메인
                - 단순 도메인
                - 복합 도메인 → 값을 하나의 단위로 취급
    - 관계 데이터베이스의 개념
        - 관계 데이터베이스
            - 테이블들의 집합
            - 데이터베이스를 시간에 따라 그 내용이 변할 수 있는 테이블의 형태로 표현
        - 관계 데이터베이스 스키마 → {릴레이션 스티마 + 무결성 제약조선}
        - 관계 데이터 모델 ↔  프로그래밍 시스템
            - 릴레이션 ↔  파일
            - 투플 ↔  레코드
            - 애트리뷰트 ↔  필드
        
        <aside>
        💡 관계 데이터베이스라고 할 때 데이터가 물리적 테이블 형태로 저장된다는 것을 의미하지는 않는다.
        
        </aside>
        
    - 데이터베이스 key
        - key
            - 각 투플을 유일하게 식별 할 수 있는 애트리뷰트 집합
        - 후보키
            - Relation에 대한 애트리뷰트 집합, K 로 다음 두 성질을 만족
                - 유일성 → 각 투플에 대해 K의 값은 유일
                - 최소성 → K 는 각 투플을 유일하게 식별하는데 필요한 애트리뷰트만 포함
        - 슈퍼키
            - 유일성은 만족하지만, 최소성은 만족하지 않는 애트리뷰트
        - 기본키
            - 후보키 중에 지정된 키 → by 데이터베이스 설계자
            - 각 투플에 대해 항상 유효해야된다 (null 설정 안됨)
        - 대체키
            - 후보키 중에 기본키를 제외한 나머지 후보키
    - Foreign key
        - 외래키
            - 릴레이션 R의 애트리뷰트 집합 FK가 릴레이션 S의 기본키 일 때 FK 는 R 의  외래키이다
            - FK의 도메인 = S의 기본키의 도메인
            - FK의 값은 S에 존재 혹은 null
            - R과 S가 같은 릴레이션 일 수 있다
            - R을 참조 릴레이션, S를 피참조 릴레이션 이라 한다
                - 릴레이션 R은 FK를 통해 릴레이션 S를 참조.
        - R ≠ S 일 경우
            
            교수 (교수번호, 교수이름, 학과번호, 직급)
            학과 (학과번호(PK), 학과이름, 학과장교수번호(FK), 학생수)
            학생 (학번, 이름, 학년, 학과)
            과목 (과목번호, 과목이름, 학점, 학과, 담당교수)
            등록 (학번(FK), 과목번호(FK), 성적)
            
        - R = S 인 경우
            
            교수1 (교수번호(PK), 교수이름, 학과번호, 학장교수번호(FK))
            
    - 무결성 제약
        1. 개체 무결성
            1. 기본 키 값은 null을 가질 수 없다
            2. 정보 부재를 명시적으로 표현하는 특수한 데이터 값
                1. 알려지지 않은 값
                2. 해당 없음
        2. 참조 무결성
            1. 외래 키 값은 반드시 피참조 릴레이션의 기본 키 값이거나 null
        
        <aside>
        💡 이러한 무결성 제약조건은 데이터베이스 상태가 항상 만족시켜야 된다
        
        </aside>
        
        - 데이터베이스 상태 → 상태의 변화에도 항상 무결성 제약조건을 만족해야한다
            - 어느 한 시점에 데이터베이스에 저장되어 있는 모든 데이터 값(투플)
            - 데이터베이스 인스턴스
                - 데이터베이스 스키마에 포함되어 있는 모든 릴레이션들의 인스턴스 집합
            - 데이터베이스 상태의 계속적인 변화
                - 삽입, 삭제, 변경 연산
- SQL
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
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2013.png)
            
            all
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2014.png)
            
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
- 정규화
    - 데이터의 논리적 표현
        - 릴레이션 스키마의 설계
            - 논리적 데이터베이스 설계
            - 관계 모델을 이용하여 어떻게 실세계를 정확히 표현 할 것인가.
            1. 애트리뷰트, 엔티티, 관계성을 파악
            2. 관련된 애트리뷰트들을 릴레이션으로 묶는다
                - 애트리뷰트들간의 관계성, 데이터 종속성
                - 효율적인 데이터의 처리
                - 데이터의 일관성
            3. 변칙적 성질의 예방
                - 데이터 변경 시의 이상
        - 이상의 예
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2015.png)
            
            - 삭제 이상(deletion anomaly)
                
                200번 학생이 'C123'과목을 등록 취소 시 200번이 3학년이라는 것도 손실
                
                → 연쇄 삭제에 의한 정보 손실
                
            - 삽입 이상(insertion anomaly)
                
                600번 학생이 2학년이라는 사실을 삽입 시 과목번호를 필수 삽입 해야된다 (과목번호가 기본키 인 경우)
                
                → 원하지 않는 정보의 강제 삽입
                
            - 갱신 이상(update anomaly)
                
                400번 학생의 학년을 4에서 3으로 변경시 학번 400에 대한 4개의 투플을 모두 변경해야된다
                
                → 중복 데이터의 일부 갱신으로 정보의 모순성이 발생한다
                
        - 이상의 원인과 해결책
            - 이상의 원인
                - 하나의 개체에 속한 애트리뷰트들 간에 존재하는 여러 개의 종속관계를 하나의 릴레이션으로 표현한다
            - 이상의 해결
                - 애트리뷰트들 간의 여러 종속관계를 분해하여 각각 하나의 릴레이션으로 표현한다
                    
                    → 정규화
                    
        - 스키마 설계와 변환
            - 스키마의 설계 : 데이터베이스의 논리적 설계
                1. 애트리뷰트들과 이들의 제약조건들을 수집
                2. 수집된 결과를 명시된 제약조건에 따라 바람직한 여러개의 릴레이션으로 분할
                    
                    → 스키마 변환
                    
            - 스키마 변환의 원리
                1. 정보 표현의 무손실 → 개선된 구조
                2. 최소의 데이터 중복
                3. 분리의 원칙 → 독립된 관계성은 별도의 릴레이션으로 분리시켜 표현
    - 함수 종속(FD)
        - 함수 종속(functional dependency : FD) 이란
            - 어떤 릴레이션 R에서, R의 애트리뷰트의 부분집합 X,Y에 대하여 애트리뷰트 X의 값 각각에 대해 항상 애트리뷰트 Y의 값이 오직 하나만 연관
                
                → 애트리뷰트  Y는 애트리뷰트 X에 함수 종속 : X → Y
                
            - 애트리뷰트 X는 Y를 (함수적으로) 결정
                - X → 결정자
                - Y → 종속자
            - X나 Y는 각각 두개 이상의 애트리뷰트 집합이 될 수 있다
            - R에서 애트리뷰트 X가 키라면 → R의 모든 애트리뷰트 Y에 대해서 X → Y 이다.
            - 함수종속 X → Y 인 경우
                
                애트리뷰트 X가 반드시 '키'라는 것을 요건으로 하지 않는다.
                
                즉, X의 어느 한 값에 대응되는 Y 값을 갖는 투플이 둘 이상 존재 할 수 있다
                
                (같은 X값을 갖는 투플의 존재가 가능함)
                
        - 함수종속 다이어그램
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2016.png)
            
            수강 릴레이션 : 수강(학번, 과목번호, 학년, 성적)
            
            기본 키 : {학번, 과목번호}
            
            {학번, 과목번호} → 성적
            
            학번 → 학년
            
            1. '학년'은 '학번'에 완전 함수 종속
            2. '학년'은 {학번, 과목번호} 에 부분 함수 종속
            3. '성적'은 {학번, 과목번호}에 완전 함수 종속
        - 완전 함수 종속과 부분 함수 종속
            
            2개 이상으로 구성된 애트리뷰트 집합 X에 대하여 X → Y 가 성립 할 때
            
            - 완전 함수 종속
                
                X’⊂X이고 X’→Y가성립되는애트리뷰트X'이존재하지않는경우
                
                종속자가 기본키에만 종속되며, 기본키가 여러 속성으로 구성되어 있을경우 기본키를 구성하는 모든 속성이 포함된 기본키의 부분집합에 종속된 경우
                
            - 부분 함수 종속
                
                X’⊂X이고 X’→Y가성립되는 애트리뷰트X'이존재하는경우
                
                릴레이션에서 종속자가 기본키가 아닌 다른 속성에 종속되거나, 기본키가 여러 속성으로 구성되어 있을경우 기본키를 구성하는 속성 중 일부만 종속되는 경우
                
            - 함수 종속에 대한 추론 규칙
                - 암스트롱의 공리
                    
                    R1: (반사, reflexive) A ⊇ B이면 A → B이다. 또한 A → A이다 
                    
                    R2: (첨가, augmentation) A → B이면 AC → BC이고 AC → B이다. 
                    
                    R3: (이행, transitive) A → B이고 B → C이면 A → C이다.
                    
                    R4: (분해, decomposition) A → BC이면 A → B이다. 
                    
                    R5: (결합, union) A → B이고 A → C이면 A → BC이다.
                    
                - 함수 종속은 데이터의 의미를 표현한다
                    - '학번 → 학년'은 '학생은 한 학년에만 속한다' 라는 것을 의미
                    - 의미적 제약 조건
                - DBMS는 함수 종속을 유지하기 위해 함수 종속을 스키마에 명세하는 방법과 함수 종속을 보장하는 방법을 제공해야 한다.
    - 기본 정규형
        - 정규형이란 (Normal Form)
            - 어떤 일련의 제약조건 (constraints)를 만족하는 릴레이션
            - 정규화 즉 스키마 변환 (S → S')으로 정규형을 만든다
        - 정규화의 원칙
            1. 정보 표현의 무손실
                - 같은 의미의 정보 유지
                - 효율적인 구조
            2. 최소의 데이터 중복
            3. 분리의 원칙
                - 독립적인 관계는 별개의 릴레이션으로 표현
                - 릴레이션 각각에 대하여 독립적인 처리가 가능
    - 제 1정규형 <1NF>
        - First Normal Form (1NF)의 정의
            - **모든 도메인이 원자값으로만 이루어진 릴레이션**
            
            <수강지도 릴레이션>
            
            - 수강지도 (학번, 지도교수, 학과, 과목번호, 성적)
            - 기본 키 : {학번, 과목번호}
            - 함수 종속 :
                - {학번, 과목번호} → 성적
                - 학번 → 지도교수
                - 학번 → 학과
                - 지도교수 → 학과
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2017.png)
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2018.png)
            
        - 1NF에서 이상
            1. 삽입이상
                
                → 500번 학생의 지도교수가 P4라고 삽입 하려 할 때 과목을 등록해야한다
                
            2. 삭제이상
                
                → 200번 학생이 'C123'를 취소하면, 200번의 지도교수가 P2라는 사실도 손실
                
            3. 갱신이상
                
                → 400번 학생이 P1 에서 P3으로 변경하는 경우, 학번이 400인 4개의 투플 모두 변경필요
                
        - 이상의 원인
            - 기본키에 부분 함수 종속된 애트리뷰트 존재
                
                → 기본키로 식별되는 개체와 무관한 애트리뷰트 존재
                
                → 두가지 독립적인 정보가 하나의 릴레이션으로 표현됨
                
        - 이상의 해결
            - 프로젝션으로 1NF 릴레이션을 분해한다 → 부분 함수 종속을 제거
    - 제 2정규형 <2NF>
        - 2정규형의 정의
            
            **→ 1NF 에서 키에 속하지 않는 애트리뷰트들은 모두 기본 키에 완전 함수 종속**
            
        - 무손실 분해
            - 프로젝션으로 분해된 릴레이션들은 자연 조인을 통해 복귀가 가능
            - 원래의 릴레이션에서 얻을 수 있는 정보는 분해된 릴레이션에서도 얻을 수 있음 (역은 성립 x)
            - R(A,B,C)에서 함수 종속 A → B 라면 R1(A,B), R2(A,C)로 무손실 분해 가능
        
        수강지도 (학번, 지도교수, 학과, 과목번호, 성적)
        
        - 지도 (학번, 지도교수, 학과) :
            
            기본 키 → 학번
            
        - 수강 (학번, 과목번호, 성적) :
            
            기본 키 → {학번, 과목번호},
            
            외래 키 → {학번} 참조 : 지도
            
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2019.png)
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2020.png)
        
        - 2NF에서의 이상
            
            <이행적 함수 종속이 존재하여 이상이 발생함>
            
            릴레이션 R에 함수 종속 A → C 가 존재하고 함수 종속 A → B, B → C가 성립 할 때 C는 A에 이행적 함수 종속이다.
            
            1. 삽입 이상 → 어떤 지도교수가 특정 학과에 속하는지 삽입이 불가능
            2. 삭제 이상 → 300번 학생의 투플 삭제 시 지도교수가 컴퓨터 공학과라는 사실을 상실
            3. 갱신 이상 → 지도교수 P1이 소속을 컴퓨터 공학과에서 전자과로 변경시 학번이 100과 400인 투플을 모두 변경해야 한다.
            
            → 프로젝션으로 2NF 릴레이션을 분해 하여 이행적 함수 종속을 제거해야된다
            
    - 제 3정규형 <3NF>
        
        **2NF이며 키가 아닌 모든 애트리뷰트들은 기본 키에 이행적 함수 종속이 되지 않는다.**
        
        - 무손실 분해
            
            원래의 릴레이션에서 얻을 수 있는 정보는 분해된 릴레이션들로부터 얻을 수 있으나 역은 성립하지 않는다
            
            ex → 학생지도와 지도교수학과로 분해한다.
            
            ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2021.png)
            
        - 3NF의 특징
            - 키가 아닌 애트리뷰트 값의 갱신 시 불필요한 부작용이 발생하지 않음
            - 모든 이원 릴레이션은 3NF에 속한다
        - 3NF의 약점
            
            <적용 할 수 없는 경우>
            
            1. 복수의 후보키를 가지고 있음
            2. 후보키들이 두개 이상의 애트리뷰트들로 구성됨
            3. 후보키들의 애트리뷰트가 중첩됨
        - 예시 (수강과목 릴레이션)
            - 제약조건
                - 한 학생은 한 교수의 강의만 수강
                - 각 교수는 한 과목만 담당
                - 같은 과목을 여러 교수가 담당 할 수 있음
            - 수강과목 (학번, 과목, 교수)
            - 후보 키 : {학번, 과목}, {학번, 교수}
            - 기본 키 : {학번, 과목}
            - 함수 종속 : {학번, 과목} → 교수, 교수 → 과목
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2022.png)
        
        - 3NF에서의 이상
            - 삽입 이상 → 교수 P5가 자료 구조를 담당한다는 사실의 삽입은 학번이 있어야 된다
            - 삭제 이상 → 100번 학생이 자료구조를 취소한다면 P2가 담당 교수라는 정보도 삭제
            - 갱신 이상 → P1이 프로그램이 과목 대신 자료구조를 담당한다면, P1의 모둔 투플을 변경
        
        → 교수가 결정자이지만 후보 키가 아니라서 발생하는 문제
        
    - 보이스/코드 정규형
        - Boyce / Codd Normal Form (BCNF)란
            - 릴레이션 R의 결정자가 모두 후보키 라면 릴레이션 R 은 BCNF이다
            - 강한 제 3 정규형이다
            - R이 BCNF라면 R은 1,2,3 정규형에 속한다
    - 고급 정규형
        
        ![Untitled](Database%2056e5988ead714869bef973222cd027aa/Untitled%2023.png)
        
        **BCNF인 CPT 릴레이션의 제약조건**
        
        - 만일 CPT에 투플 <c1, p1, t1>과 <c1, p2, t2>가 포함되어 있다면 두개의 투플 <c1, p1, t2>와 <c1, p2, t1>도 포함되어 있어야 된다.
        
        **CPT 릴레이션에서의 변경 이상**
        
        - P4가 데이터베이스를 담당한다는 정보를 삽입하려면, 3개의 데이터베이스 교재 (T3, T4, T5) 에 대한 투플을 삽입해야 된다.
        
        **BCNF 이상의 원인**
        
        → 과목은 교수나 교재의 값 하나를 결정하는 거싱 아닌 값의 집합을 결정
        
        **다치 종속**
        
        - A, B, C가 릴레이션 R의 애트리뷰트의 부분 집합이라 할 때 애트리뷰트 쌍 (A, C)값에 대응되는 B 값의 집합이 A 값에만 종속되고, C 값에는 독립적이면 B 는 A 에 **다치종속**이며 A↠B 로 표기된다.
        - A ↠ B 이면 A ↠ C 도 성립되면 A ↠ B | C이다.
            - CPT 릴레이션에서 과목 ↠ 교재 이기에, 과목 ↠ 교수도 성립된다.
        - 모든 FD 는 MVD이다.
            - A → B 라면 A ↠ B 이다.
        - MVD를 가진 릴레이션의 분해
            - R(A,B,C)에서 MVD A ↠ B | C를 만족하면, 두 프로젝션 R1(A,B)와 R2(A,C)는 무손실 분해이다.
    - 제 4정규형 <4NF>
        
        
    - 제 5정규형 <5NF>
- 모델링
- Database의 설계