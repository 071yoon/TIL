# 정보보안

## 정보보안의 목표

- 기밀성 : 인가되지 않은 사용자에게 ..
- 무결성
- 가용성

## 정보 보안의 기본 용어

- 인증 : 송 수신자가 정당한지 확인
- 부인 방지 : 송수신 여부에 대한 부인을 방지

  - 송신 부인 방지
    - 메시지를 송신하고도 송신하지 않았다고 주장하는 송신자의 부인을 방지
  - 전달 부인 방지
  - 수신 부인 방지
    - 메시지를 받았음에도 수신하지 않았다고 주장

- 암호화 기술 : 암호화 키와 복호화 키가 같은 `대칭 키 암호방식`과 암호화 키와 복호화 키가 서로 다른 `공개키 암호 방식` or `비대칭 키 암호방식`이 존재

- 전자서명
  - `개인키`를 이용하여 해쉬 연산을 함
  - 메시지에 대한 해쉬 값을 계산한 후 이것에 대해 서명함
- 해쉬함수

  - 고정된 길이의 짧은 해쉬값으로 변환
  - 임의의 길이를 갖는 입력 비트열을 고정된 짧은 길이로 함축
  - 해쉬 함수는 키를 사용하지 않으므로, 같은 입력에 대해 항상 같은 출력을 가질 수 있음
  - 무결성 검증

- 악성코드
  - 웜
    - 독립적으로 실행되는 악의적인 코드로, 다른 컴퓨터로 확산
  - 바이러스
    - 다른 독립적 프로그램에 삽입되어 발생
  - 트로이 파일
    - 악성코드가 숨겨진 프로그램으로 정상적으로 보임
- 보안 솔루션
  - 방화벽
    - 사설 네트워크를 외부로부터 보호하기 위해 공중 네트워크와 사설 네트워크 사이에 설치하는 보안 솔루션
      - 패킷 필터링 게이트웨이로 일련의 규칙을 밭앙으로 패킷의 통과 여부를 판단
      - 프록시 서버로 사설 네트워크로 접속하기 위해 특정 호스트들에게 인증을 제공 및 패킷을 전달하도록 허가
  - IPS 침입 방지 시스템 (Intrusion Protection System)
    - 불법 행위를 구별하여 실시간으로 침입을 차단
    - IDS는 탐지만 함에 주의
  - VPN
    - 사설망을 물리적으로 구축하지 않고, 인터넷과 같은 공중망을 사설망처럼 안전하게 구축
    - IPSec과 SSL로 구성
  - SSO 통합인증 (Single Sign on)
    - 하나의 사이트에 로그인 한 후, 여러 다른 사이트에 별도의 인증절차 없이 자동으로 인증할 수 있음
  - WAF 웹 방화벽 (Web Application Firewall)
    - 웹 서버 압쪽에 위치하여 외부로부터 들어오는 HTTP/HTTPS 프로토콜에 대해 트래픽을 감시
    - SQL Injection이나 XSS 공격등을 탐지하여 차단하는 보안 솔루션
  - NAC 네트워크 접근 제어 시스템 (Network Access Control)
    - 사용자 컴퓨터가 처음 내부망 네트워크에 접근을 시도할 때 접근하는 사용자 컴퓨터에 대해 네트워크 사용자 인증 수행 및 백신 프로그램 설치 등 각종 보안 정책 준수 여부를 확인
    - 유/무선 인터넷 접속 시 인증 후 접근시켜준다 -> naver.com 접속하면 탐지 ON
    - 보안정책 미 준수 시 사전에 정의된 보안 정책에 따라 네트워크 접근을 통제
  - WIPS 무선 침입 방지 시스템 (Wireless Intrusion Prevention System)
    - 인가되지 않은 무선장비들의 접근을 자동으로 탐지 및 방지
    - WIPS는 노출된 무선 네트워크에서 불법 AP나 사용자 단말기를 이용한 침입 시도 공격 등을 탐지 및 차단
  - ESM 통합 보안관리 (Enterprise Security Management)
    - 보안관리 기능을 통합하여 일간되고, 직관적인 관리자 및 사용자 인터페이스를 제공
  - SIEM 보안 정보 및 이벤트 관리
    - 기존의 ESM 역할을 보안 영역에서 기업 전반으로 확대

## 정보보안 신기술 용어

- 블록체인
  - 하나의 공개 장부에 기록되고 분산되어 저장되는 단일장부
  - 거래가 발생하게 되면 거래된 정보의 검증을 위해 일정시간(10분)동안 발생한 거래를 모아 블록을 생성하고, 이러한 블록들을 순차적으로 연결하여 체인을 이룬다
  - 거래 원장의 복사본이 각 네트워크 구성원에게 분산되어 새로운 거래가 발생할 떄 마다 구성원들의 동의를 통해 해당 거래를 인증하게 된다
    - P2P 네트워크 방식을 이용
    - 거래 중개자의 개입이 불필요하게 된다
    - 거래의 효율성과 투명성이 높아진다
    - 적은 비용이로 가능하다
    - 위변조가 불가능하다
- FIDO(Fast IDentity Online)
  - 온라인 환경에서 비밀번호를 대체하는 안정성이 있는 인증방식
- 망분리와 망 연계
  - 물리적 망분리
    - PC 2대
  - 논리적 망분리
    - PC 1대 -> 가상화
- 양자암호
  - 수학적 복잡성을 기반으로 기존의 암호체계와 달리 양자암호를 사용
  - 원래의 상태로 되돌릴 수 없음
  - 도청을 위해 측정하는 순간, 상태를 변화시켜 도청 시도를 파악할 수 있다
- 신뢰 플랫폼 모듈 (TPM, Trusted Platform Module)
  - 이미 암호화된 키, 패스워드, 디지털 인증서들은 하드웨어적으로 분리된 안전한 공간에 저장하여 키 관리나 암호화 처리가 필요
- 재식별화 (re-identification)
  - 개인을 식별 할 수 없도록 변환하는 과정이나 방법을 비식별화라 하는데, 이를 다시 식별 할 수 있도록 다른 정보와 조합 분석 처리하여 개인을 식별해내는 과정

## 암호 기술

- 암호의 개념
  - 평문을 해석하기 불가능한 형태의 암호문으로 변형
    - key를 사용
    - 기밀성을 얻을 수 있음 (원하는 사람만 받을 수 있음)
- 암호화, 복호화
  - 암호화란 제 3자가 인식할 수 없는 형태로 변환하는 과정
  - 복호화는 암호화의 역과정으로 변환된 암호문을 평문으로 복원
- 암호화 기술
  - 대칭키 암호화 기술 : 키가 하나
  - 공개키 암호화 기술 : 키가 둘
- 비밀키 암호 알고리즘
  - 암호화 키와 복호화에 사용하는 키가 동일
  - 암호화의 복호화 연산이 빠르다
  - 거리가 먼 경우 키를 공유하는 방법에 어려움 존재
  - 상대가 많은 경우, 서로 다른 키를 생성하고 유지하는데 어려움
  - 키를 비밀리에 보관 및 관리가 복잡함
  - 블록 암호화
    - 블록 단위를 나누어, 고정 길이의 입력으로 나누어 구현
    - 구현에 용이
  - 스트림 암호화
    - 비트 단위로 암호화
    - 이동 통신 환경에서 용이
    - 느림 + 쉽게 내용 변경 가능
- 공개키 암호화

  - 1976년 디페와 헬만에 의해 공개키 암호화가 도입
  - 송신자와 수신자가 서로 다른 키를 사용
  - 송신자는 수신자의 공개키를 사용하여 암호화한 결과를 전송
  - 수신자는 자신의 공개키에 대응하는 개인키를 사용하여 데이터를 복호화

- RSA
  - 큰 정수의 인수분해의 어려움에 안전성을 두고 있다
- ECC

  - 타원곡선 암호방식으로, 안정성이 높고 속도가 빠르다

- 해쉬 함수
  - 다양한 크기를 갖는 임의의 데이터로부터 고정된 길이의 짧은 해쉬 값을 출력하는 수학적 함수
  - 키가 없음! 암호화 X -> 그저 변환이다!
  - 무결성을 검증할 수 있다
  - 역상 저항성 -> 반대로 찾기가 어렵다
  - 제2 역상 저항성 -> h(x) 에서 h(x') 이면 찾는것이 어려움
  - 충돌 저항성 -> h(x) = h(x') 인 x와 x'를 찾는것이 어려움
  - MD5
  - SHA : 256이상인 해쉬 함수를 사용해야된다
  - 해쉬 함수의 보완
    - 솔트(Salt)를 사용하여 해쉬 값을 생성할 때 추가되는 비트열을 추가 -> Salting

## 인증기술

- 사용자 인증
  - 신원확인
  - 메시지 인증
- 인증방식

  - 지식 기반 인증
    - 패스워드
  - 소유기반 인증
    - OTP, 스마트카드
  - 존재기반 인증
    - 홍채인식, 지문인식, 음성인식, 얼굴인식
  - 패스워드 정책
    - 인증 시스템은 실패 로그인 시도 횟수 제한이 필요
  - 패스워드에 대한 공격기법
    - 무차별공격
    - 사전공격
    - 트로이 목마, 패스워드 파일에 대한 직접 접근 및 사회공학적 기법
  - OTP 인증
    - 매 세션마다 일회용 패스워드를 생성하여 입력하는 일회용 패스워드 생성기를 사용
    - 시간 동기화 : 인증서버와 클라이언트 간 시간을 동기화하고, 시간을 입력값으로 하여 일회용 비밀번호를 생성
  - 멀티팩터 인증
    - 복수의 인증 요소를 사용
  - 전자서명
    - 공개키 암호 방식의 기본 가정은 공개키에 대해 쌍이 되는 개인키는 사용자가 안전하고 비밀스럽게 보관한다는것
    - 전달하고자 하는 메세지와 해쉬값인 메시지 다이제스트를 개인키로 암호화한 결과를 전자서명으로 전달
  - PKI (Public Key Infrastructure)
    - 공개키 관리를 위한 기반 구조
    - PKI 구성 요소
      - CA(인증기관)
      - RA(등록기관)
      - 인증서 소유자
      - 사용자
      - 공개키 인증서와 CRL 저장소
        - 전자서명 검증키와 소유자 관계를 증명해 주는 전자적 파일
        - 패기된 인증서들의 목록을 관리하기 윟나 CRL 저장소
  - 공개키 인증서
    - 금융거래 및 전자상거래에 사용하기 위한 NPKI 인증서와 행정기관에서 행정업무용으로 사용하는 GPKI 인증서가 있음

- 인증서 유효성 검증방법

  - CRL(Certificate Revocation List) : 인증서 폐기 목록
    - 폐기된 인증서의 Serial, 폐기 날짜, 폐기 사유 등을 담고 있음
  - OCSP (Online Certificate Status Protocol) : 온라인 인증서 상태 프로토콜

- 식별
- 인증
- 인가

- 접근통제
  - 강제적 접근통제 : MAC (Mandatory Access Control)
    - 주체에게 보안등급을 부여하고, 객체에게는 보안 레이블을 부여한 후 사전에 정한 규칙에 따라 해당 주체가 객체에 대하여 접근이 가능한지 여부를 판단 -> 군사적 목적으로 사용
  - 임의적 접근통제 : DAC (Discretionary Access Control)
    - 주체의 계정 또는 계정이 속한 그룹의 신원에 근거하여 객체에 대한 접근을 제어
  - 역할기반 접근통제
    - 역할에 따라 접근이 가능한 객체를 매핑
  - 접근통제 모델
    - Bell-Lapadula
      - 강제적 정책에 의한 접근 통제 모델
      - 정보의 불법적인 파괴나 변조보다 기밀 유출 방지에 중점을 둠
      - 정보가 높은 레벨에서 낮은 레벨로 흐름을 방지
    - Biba
      - 위의 단점을 보완하여 무결성을 보장하도록 만들었음

### APT 공격

- 엔드포인트 보안
- 중요정보 암호화 및 DLP -> DRM으로 발전

### 파밍

- 호스트 파일을 변조
  - 피싱사이트로 유도되어 금융정보나 접속 정보를 탈취

> 피싱 vs 파싱

### 큐싱

QR코드로 피싱

### 스미싱

SNS + 피싱

### 크립토재킹

### 랜섬웨어
