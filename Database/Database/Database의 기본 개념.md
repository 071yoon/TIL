# Database의 기본 개념

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
        
        ![Untitled](WhatIsDB/Untitled.png)
        
    - 관계란
        - 속성 관계
            - 개체 내 관계 : 특성
        - 개체 관계
            - 개체 간 관계
        
        ![Untitled](WhatIsDB/Untitled%201.png)
        
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
    
    ![Untitled](WhatIsDB/Untitled%202.png)
    
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
        
        ![Untitled](WhatIsDB/Untitled%203.png)
        
    
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
    
    ![Untitled](WhatIsDB/Untitled%204.png)
    
- 데이터베이스 관리 시스템의 정의
    - DBMS(Database management system) 이란?
        
        응용 프로그램과 데이터 사이의 중재자로 모든 응용 프로그램들이 데이터베이스를 공용되게 사용 할 수 있게 관리해 주는 범용 소프트웨어 시스템
        
    
    ![Untitled](WhatIsDB/Untitled%205.png)
    
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
    
    ![Untitled](WhatIsDB/Untitled%206.png)
    
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
        
        ![Untitled](WhatIsDB/Untitled%207.png)
        
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
        
        ![Untitled](WhatIsDB/Untitled%208.png)
        
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
        
        ![Untitled](WhatIsDB/Untitled%209.png)
        
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

![Untitled](WhatIsDB/Untitled%2010.png)
