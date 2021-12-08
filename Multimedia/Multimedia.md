# Multimedia

- What is Multimedia
- Signal
- Sound
- Video
- Lossless Compression
- JPEG
    - Introduction
        - JPEG이란
            - Joint Picture Experts Group의 약자
            - ITU-TS(추후 ITU-T)와 ISO의 Joint로 만들어진 화상 처리 전문가 모임
            - 1992년의 ISO표준 채택 이후 정지 영상의 Format을 일컫는다
            - ISO/IEC 10918
                - ISO/IEC가 공동 개발한  표준 번호
                - 4개의 파트로 표준 정의
                - 현재는 7개로 확장되었다
            - 애니메이션/그래픽 이미지 기반 → JPEG의 등장 → 자연에서 획득한 영상
                - 색이 조금씩 변하는 현상까지 압축 가능
        - 발전과정
            - ISO/IEC 10918-1  : 1994 Information Technology
                - 실질적으로 JPEG을 압축하는 방법이 고안
            - ISO/IEC 1091-2 : 1995 Information Technology
                - Compliance Testing(부합성) : 찍은 사진이 JPEG 규격을 만족 할 수 있는지 확인 할 수 있는 방법
            - ISO/IEC 10918-3 : 1997 Information Technology
                - Digital compression and coding of Continuous-tone still Images : Extensions
            - ISO/IEC 10918-3 : 1997/Amd 1:1999
                - Provisions to allow registration of new compression types and versions in the SPIFF header
            - ISO/IEC 10918-4 : 1999 Information Tehcnology
                - 같이 적용 할 수 없거나, 독립적으로 적용 할 수 있는 여러 기술이 섞여 규격에 포함됨
                - Profile : 미리 선택한 도구의 세트로 하나의 인코더를 제작
                - SPIFF Profiles의 정의 및 등록
            - ISO/IEC 14485-1 : 1999 Informatino Technology
                - JPEG-LS의 표준 정의 → Baseline
            - ISO/IEC 15444 Series : JPEG 2000 표준 최초 제정
                - Wavelet Transform에 기반
                - 극장에서 사용
        - 대표적 4가지 Mode의 JPEG
            - Lossy Sequential DCT-Based Encoding(Baseline Mode)
                - Left to Right, Top to bottom 의 single scan
                - Mandatory JPEG Mode
            - Expanded lossy DCT-Based Encoding (Expanded Lossy Mode)
                - Baseline Mode의 확장
                - 대역폭이 낮을 때 화질은 떨어지지만 빠른 이미지의 디코딩을 가능하게 해 주는 다중스캔에 기반한 점진적(Progressive) Mode 지원
            - Lossless and Near-lossless compression
                - 무손실 압축을 지원
            - Hierarchical Encoding
                - 다중 해상도 Encoding
    - Source Image Model
        - JPEG으로 압축하기 전, 원래 이미지를 어떻게 받아들일지 또는 어떤 모습을 가지고 있는지 가정
        - JPEG은 1~255개 까지의 Component/Plane 지원
        - 컬러모델
            - RGB Channel
            - Component Video Channel
            - Alpha Channel
            - CMYK Channel
            - 255개 까지 늘어 날 수 있다
        - 각각의 Component들은 수평/수직축에 따라 서로 다른 Pixel의 수를 가질 수 있다 (최대 2$^1$$^6$ x 2$^1$$^6$) → (x, y)
            - Chroma Subsamplign Y, U, V Channel
            - 가로로 x, 세로로 y, 픽셀을 가질 수 있고, Component별로 크기가 다를 수 있다
        - 같은 Component에 속하는 Pixel들은 같은 Pixel 깊이를 가진다
            - Component 컬러값을 정의 할 때 사용하는 bit수가 동일
            - Basline Mode → 8bit
            - Expanded Lossy Mode → 8bit or 12bit
            - Lossless Mode → 2bit to 16bit
        - 전체 이미지의 크기는 Component 별로 다르다
            - 가장 큰 Component는 $x$ x $y$의 사이즈라고 가정하면
            
            ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled.png)
            
            - Component의 상대적인 크기를 나타낸다
            - 1~4 사이의 정수를 가지기 때문에 x의 가장큰값은 4
            - 𝐻𝑚𝑎𝑥 는 2 또는 4이다
            - 가장 큰 Component와 인코딩하려는 Component크기의 비 : 𝐻𝑖 / 𝐻𝑚𝑎𝑥
            - H가 1~4의 정수 이므로, 비율이 고정된다
    - Data Unit
        - Data Unit 이란
            - Interleave
                - 한 이미지를 부분별로 여러 성분의 데이터 유닛을 섞어 압축
            - Non-interleave
                - 하나의 이미지를 각각 독립된 성분만으로 구성된 이미지의 합으로 생각
                - 각각의 성분별로 압축을 진행
                    
                    → 상기한 여러개의 성분들로 구성된 이미지를 처리하기 위한 방식
                    
            - JPEG은 4개 Component의 Interleaved Coding을 지원
            
            ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%201.png)
            
            - 최소단위 : MCU (Minimum Coding Unit)
    - Baseline Mode (Lossy)
        - Data Unit의 부호화 (압축)
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%202.png)
        
        - 각각의 Component들이 8x8 Pixel의 Block으로 나누어 진다
        - 각 Block에 대하여 2차원 DCT 적용
        - 각각의 8x8 Block에 대한 Encoding 된 Sequence 가 나온다
        - 64개의 DCT 계수값은 미리 정해진 양자화 Table에 의거해 양자화됨
        - 전환된 각 Component중 U,V Component는 색채 정보에 둔감한 시각의 특성을 이용하여 수평,수직 방향 모두 1/2로 Down Sampling 된다
            - Chroma Subsampling이 4:2:0
            - Y Component는 H=2, V=2
            - U,V Component는 H=1, V=1
        - 양자화 Table 값은 각 DCT 계수들의 중요도에 따라 결정된다
        - 덜 중요한 계수의 양자화 값 → 큰 값
        - 4개의 양자화 Table을 Decoder에 저장하는것이 가능하다
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%203.png)
        
        - 양자화된 계수들은 Entrophy Coding을 위하여 Zig-zag로 Scan되어 1차원 Sequence를 이룬다
        - DC : 첫번째 계수 (0의 위치) → Block의 평균 강도(빛의 세기)
        - AC : 1~63 번째의 계수 → Run-length Coding
            - Symbol-1
                - AC 계수 바로 앞에 나오는 0의 개수와 자기 값을 나타내기 위하여 필요한 bit 수
                - 0의 최대 개수는 15, 넘으면 (15,0)으로 표시 후 다시 시작
                - (0,0) 은 Block의 끝을 의미
            - Symbol-2
                - 자신의 값을 나타내는 bit 수
        - Data Unit의 복호화
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%204.png)
        
        - Entrophy Decoder를 통해 양자화 된 계수값이 나온다
    - Expanded Lossy Mode
        - Expanded Lossy 와 Baseline의 차이
            - 8bit pixel 대신 12bit Pixel Depth 선택 가능
            - Entropy Coding 과정에서 Huffman Coding 대신 Arithmetic Coding 선택 가능
            - Sequential Encoding외에 Progressive Encoding 선택 가능
        - DCT Progessive Mode
            - DCT Sequential Mode와 동일한 DCT와 양자화 과정
            - 각 이미지 Component가 Multiple Scan에 의하여 Encoding
                - Multiple Scan → Spectral Selection(주파수 선택)
                    - DCT 계수들을 연관된 Spatial Frequency 에 따라 주파수 대역별로 그룹핑
                    - 각 Scan마다 다른 주파수 대역을 Coding
                    - DC 계수들로부터 Scan 하여 Coding
                    - 저주파 대역에서 고주파 대역이 추가되어 화면이 점차 선명해진다
                    - 대역의 수 (Scan의 수)는 화질의 진행 정도와 구현의 Overhead등을 고려하여 결정
                - Multiple Scan → Successive Approximation(점진적 근사)
                    - DCT 계수의 정밀도를 증가
                    - 2$^n$의 값으로 DCT 계수들을 나누어 Coding 후, Decoder는 받은 값을 같은 값으로 곱하여 IDCT를 수행 → 복원
            - DCT 계수를 버퍼 메모리에 저장 → 이미지 복원에 필요한 최소 계수들부터 Entropy Coding → 완전한 이미지 Encoding
        - Hierarchical Mode
            - 수평/수직 방향 또는 양방향으로 2배씩 감소하는 Resolution 몇 단계에 거쳐 피라미드 모양으로 Encoding
                1. 소스 이미지를 각각 방향과 2의 배수로 원하는 횟수만큼 Down Sampling하여 가장 저해상도의 이미지를 구함
                2. 구해진 저해상도의 이미지를 원하는 Mode의 JPEG Coding
                3. Coding 된 이미지를 다시 Decoding하여 원하는 방향으로 Upsampling을 통해 2배 증가한 Prediction 이미지 구함
                4. Down Sampling으로 복원한 동일한 해상도 이미지의 차이를 구해 원하는 Mode의 JPEG Coding
                5. Full 해상도 이미지가 Coding되는 동안 3. ↔ 4. 반복
                6. 여러 단계에서 얻어진 해상도를 지원하는 이미지 제작
    - Sequential Lossless Mode
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%205.png)
        
        - Lossless Mode : DCT 변환을 하지 않는다
        - Lossy Mode : DCT 기반의 부호화 과정을 거친다
        - 압축 과정 :
            - 선택된 Prediction Value와 실제 Pixel값의 차이를 구하여 Huffman / Arithmetic Coding을 진행
            
            ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%206.png)
            
    - JPEG Data Format
        
        Image Level
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%207.png)
        
        Frame Level
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%208.png)
        
        Scan Level
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%209.png)
        
        Segment Level
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%2010.png)
        
        Hierarchical Mode
        
        - Image Levelx에서만 비계층형과 차이를 보인다
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%2011.png)
        
        - JPEG 응용 → 표준
            - Hierarchical Mode는 해상도를 달리하는 다양한 Client의 요구를 만족
            - JPEG-2000이라 불리는 표준을 제정하여 극장에서 사용
    - Summary
        - Baseline Mode
            - 가장 기본적인 JPEG
            - Sequential DCT 기반 Encoding
        - Expanded Lossy Mode
            - 빠른 이미지의 Decoding을 가능하게 해 주는 다중 Scan에 기반한 점진적 Mode
        - Hierarchical Mode
            - 이미지의 다중 해상도 Decoding지원
        - JPEG Data Format
            - 비계층형
            - 계층형
        - JPEG 응용
            - 일반 용도의 압축 표준을 목표
- Video Compression
    - Video Compression Technology
        - 일반적으로 Lossy Compression
        - Perceptually Lossless Compression → 우리가 느끼기에
            - 사람의 시각 특성을 이용하여 인식되지 않는 신호 제거
            - Bit rate를 감소시키는 Noise의 추가 및 다양한 방법 사용
            - Data Redundancy의 제거만으로 이루어지지 않는 높은 압축률
        - Application별로 전달해야 하는 정보의 특성이 달라질 수 있다
            - 특정한 신호의 제거를 통한 추가 압축이 가능
    - Video Stream's Data Redundancy
        - Spatial Redundancy (공간적 중복성)
            - Image의 인접한 픽셀들은 같은 색 정보 또는 유사한 색 정보를 갖는다
            - 인접한 픽셀의 정보는 인접한 픽셀과의 차이와 같은 간단한 정보로 표현
        - Temporal Redundancy (시간적 중복성)
            - 시간적으로 연속해서 나타나는 Sample들이 유사한 정보를 갖는다
            - 인접한 Frame들은 매우 유사한 이미지를 가진다
            - 한 Frame 전체가 인접한 Frame과의 차이로 표현
    - Noise Masking
        
        → 인간의 시각
        
        - 색채의 변화 < 밝기의 변환 (더 민감하다)
        - 밝은 부분에서 밝기의 차이(상대적으로 둔감) < 어두운 부분에서 밝기의 차이
        - 공간적으로 높거나 낮은 주파수 (둔감) < 중간  주파수 신호
        
        → 이미지의 인식 방법
        
        1. 실제로 망막에 비치는 이미지가 공간적 주파수에 따라 몇개의 Subband로 나뉨
        2. 각 Subband별로 다른 Sensitivity를 가지고 인식한다
        3. 이러한 특성들을 이용해 높은 압축률을 이룬다
    - Spatial & Temporal Subsampling Coding
        
        → 특정한 Application에서 Full-Resolution은 필요하지 않는다
        
        - Spatial Subsampling
            - 몇개의 인접한 픽셀에서 하나의 픽셀을 선정
        - Temporal Subsampling
            - 인접한 몇개의 Frame에서 하나의 Frame을 선택
        
        → Application에서 필요로 하는 정도의 정보를 전달하여 높은 압축률을 이룬다
        
        1. 8개의 픽셀마다 하나의 픽셀을 선택
        2. Frame Rate를 30 → 15로 낮춘다
        3. 128:1의 압축률을 이룰 수 있다
        
        → 다른 압축 기술들을 추가하여 더욱 높은 압축률을 만들 수 있음
        
        - Decoding 단계
            - Application에 따라 크기가 작은 영상을 낮은 Frame Rate로 전달
            - 받은 정보만을 Interpolate하여 질이 떨어지는 영상을 원래와 같은 크기의 Frame Rate로 복원 가능
    - Predictive Coding
        
        → Picture 신호의 통계적 특성과 인간의 시각 특성을 고려하여 압축
        
        - Picture 신호의 공간적 연관성은 인접한 Pixel의 예측을 가능하게 해준다
        - 예측치와 실제값의 차이는 실제값보다 항상 작은 Variation을 가진다
        - Frame간의 연관성을 이용하여 인접한 Frame의 예측을 가능하게 한다
        - 예측치와 실제값의 차이 또한 실제값보다 항상 작은 Variation을 가진다
        
        → 예측값의 차이만을 가지고 양자화/인코딩 시
        
        - Variation이 작다 → 양자화 할 최고값이 작다 → 양자화할 Level의 수가 적어지고, 같은 질을 유지 할 떄 샘플당 할당하는 bit수가 적어진다
        - 압축률 증가 → 같은 질 유지, 압축률 유지 → 더 좋은 화질
        
        → 비선형적 양자화 방법
        
        - A-law 와 u-law 이용
        
        → 인간의 인식 체계에 따른 빛의 세기
        
        - 빛의 세기가 약하다 → 촘촘, 강하다 → 띄엄띄엄 (같은 bit 할당 시 더 좋은 화질 유지 가능)
        
        → 높은 Amplitude 를 가질 경우 → Quantization Noise 증가
        
        - 같은 bit 사용 시 영상의 질 증가
        - 동일한 영상의 질을 유지하려면 bit rate를 감소시켜 압축률 증가
    - Conditional Replenishment
        
        이미지를 정적 영역과 동적 영역으로 분리하여 동적 부분만 코딩하여 전송
        
        → 변화가 발생하는 부분만 분리하여 움직이는 부분을 합쳐 압축률을 높힌다
        
        1. 인접한 Frame간의 차이를 구한다
        2. 일정 임계치 이상의 차이를 보이는 픽셀만 추림
        3. 고립된 색소나 아주 작은 색소의 덩어리를 제거
        4. 전송 시 Cluster의 시작 주소 신호를 전송하고, 양자화된 차잇값, Cluster의 끝 코드 발송
    - Motion Estimation and Compression
        
        Predictive 하게 비디오의 Temporal Redundancy를 제거
        
        → 한 픽셀의 모션이 발생하였다 하면 그 픽셀이 이전 이미지에서는 다른 위치에 존재하였음
        
        1. 한 이미지는 몇개의 정해진 크기의 블록으로 나뉜다
        2. 각 블록과 가장 일치하는 블록을 이전 이미지에서 찾는다
        
        Motion Vector와 Pixel Difference Block을 코딩하는것이 Block을 코딩하는것 보다 효율이 높음.
        
    - Transform Coding
        1. 통계적으로 관련되어 있는 이미지의 요소들을 독립적인 요소들로 변환
        2. 이미지의 에너지를 소수의 계수에 집중시켜 이미지의 중복성을 제거
        
        - 하나의 이미지를 공간상의 몇개의 블록이나 Sub-image로 나누어 각각의 부분 이미지에 Unitary Mathematical Transform에 적용시켜 공간 주파수로 변형
        - 대부분의 에너지는 저주파 지역의 소수 샘플에 집중
        - Spatial Domain에서 연관성이 높은 데이터는 변환의 특성상 주파수 공간으로 변화 시켰을 때 Huffman Coding / Run-length Coding으로 데이터를 줄이기 용이함
        
        ![Untitled](Multimedia%2001fa55c4f2c94b66a19b394389e19652/Untitled%2012.png)
        
- MPEG
    - MPEG-1 Introduction
        - 1998년에 설립 → Moving Picture Experts Group
        - 1992년 11월 → 1.5 Mbps 의 MPEG-1
        - 1994년 11월 → MPEG-2
        
        → Coding of moving pictures and associated audio for digital storage media(CD-ROM) at up to about 1.5Mbit/s
        
        - 이후 CD-ROM 기술이 발전하여 bit rate 증가
        - CD-ROM의 저장 용량을 고려할 때 1.5Mbps 로 낮춰야 60~90분의 동영상
    - MPEG 작업의 원칙
        1. Stick to the Deadline
        2. A-Priori Standardization
        3. Not Systems but Tools → 전체 System이 아닌 도구들의 Set
        4. Specify the Minimum → 최소한만 규정
        5. One Functionality-One Tool → 하나의 기능을 위해서는 하나의 도구 선택
        6. Relication of Tools → 도구 재사용
        7. Verification of Standard → Standard에 맞는 Software, Bit Stream 등을 제작하여 완전한 표준 제공
    - MPEG-1
        
        
- H261
- H264