# 1~5장 정리

## Color

- 종류
    - RGB 는 더해지는 색 (더할수록 어두워진다)
    - CMY 는 프린트용 감소
    - HSI 는 인식이나 그림
    - YIQ 는 TV 압축용
- Histogram
    - 이미지를 나타낸다
    - 빠르게 계산이 쉽다
    - 크기의 정규화가 쉬워 비교가 간단
    - database query에서 색 매칭이 된다
    - 색의 분포를 표로 나타낸것 (HSI로)
- Point Processing
    - range transform G(x,y) = T(f(x,y)) 이다
    - Arithmetic / logic operations
        - 모든 화소값에 일정한 상수를 산술연산
    - Simple gray level
        - Power-law transformation
            - 그냥 감마 조절해서 낮으면 더 밝게
            - 감마 제곱해서 높으면 더 어두움
        - Contrast
            - 가장 어두운 영역 → 밝은 영역
            - Stretching 으로 낮은 부분 높은 부분 잡아서 쭉 땡기기
            - 더 확실하게 보인다
            - ends-in search
                - 잘 안쓰는 애들을 흰색이나 검정으로 몰아넣고 stretch
            - function 써서 밝은애 더 밝게, 어두운애 더 어둡게도 가능
    - Histogram processing
        - Histogram Equalization
            - histogram들 얼추 다 비슷하게 맞추기
            1. image histogram 만들기
            2. look-up table 정규화해서 합으로 계산
                1. 0 부터 n 까지 개수 세기
                2. sum * (max num / 전체 칸수) = 새로운 수
            3. look-up table 로 다시 재구성
- Noise
    - salt & pepper : 흰색 검정 점들
    - impulse noise : 흰색
    - gaussian noise: 가우시안 분포에서 튀게
    - mask filtering
        - 그냥 3x3 평균 내기
    - Kernel
        - convolution mask 가 1이면 → 원본과 동일
        - 0이면 edge detection
    - gaussian filtering
        - 1 2 1
        - 2 4 2
        - 1 2 1 가중치로 convolution
    - median filtering
        - reducing noise 에서 convolution 보다 효과적
        - non-linear operation
    - high-boost filtering
        - 낮은 주사율을 살리면서 높은 주사율을 개선시에 더 좋다
        - high-boost = A*original - lowpass
        - high-boost = A*original + lowpass
- Structuring Elements
    - mask 모양을 만들고 operation → convolution 한다
    - dilation
        - 채우거나, 키울 때 사용
        - 합 연산자로 사용
        - noise 도 커진다
    - erosion
        - 줄이거나, 삭제할 때 사용
        - 빼기 연산자로, 완전히 중복되는것만 살림
    - erosion → dilation 시 이뻐진다 → opening
    - dilation → erosion → closing

## Edge

- 확실하게 구분 가능한 경계
- 강한 대비가 있는 애들을 모은다
- 유용한 정보가 있는 애들을 필터링
- Steps
    - Smoothing : Noise reduction
    - Enhancement: Edge sharpening → edge operators
    - Detection: 어딜 버리고 어딜 남길지
    - Localization: 정확한 정보를 파악
- Mask for Computing Gradient (Classic)
    - 원래는 2차 미분해서 사용했음
    - Sobel:
        - 1    2   1
        - 0   0   0
        - -1 -2 -1
    - Prewitt
        - -1  0  1
        - -1  0  1
        - -1  0  1
    - Roberts
        - 0  1
        - -1 0
- Zero-crossing
    - Laplace
        - 0  -1  0
        - -1  4 -1
        - 0  -1  0
- Gaussian based filte
    - Marr and Hidreth
        1. smooth image via gaussian
        2. apply laplace filter (2차 미분 예측)
        3. find zero-crossing
    - Canny operator
- Noise 의 효과
    - 유효한 difference filter는 노이즈에 반으잉 크다
    - image smoothing 으로 해결 가능

## Region Segmentation

- 목표 : 이미지에서 비슷한 구역을 찾기
    - 비슷한 특징을 가져야된다
- 장점 : 노이즈가 껴도 괜찮다
- 단점 : region 이 너무 많거나, 적을 수 있음
- Criteria : 비슷한것들을 묶는것이 중요하다
- Region Growing
    - 가능성있는 하나의 픽셀에서 시작
    - 너무 다르지 않다면 계속 번진다
    - 첫 픽셀은 이미지에서 라벨 안된 첫 픽셀이거나, 랜덤시드중에 하나 일 수 있음
- Split and Merge
    - 4개의 구역으로 나눈다
    - 더 쪼갤 수 없다면 합친다
- Clustering
    - 어떠한 그룹에 속해있으면 더 비슷하다고 판단
    - 여러 방법이 있음 (connectivity, centroid, distribution, density...)
    - Centroid → 무게중심
        - 연산이 짧다
        - K-means
            1. ic (iteration count) = 1
            2. random K means 구하기 m1(1), m2(1), ... mk(1)
            3. 모든 vector 마다 1 ~ k 로 가장 가까운 Cj 로 선정
            4. ic 1 로 증가 후 mean 도 업데이트
            5. 3~4 계속 반복 후 C(ic) == C(ic + 1) 일때까지

## Textures

공통 부분을 partition 해서 분류하기 위해 사용

이미지에 대한 색과 강도에 대한 이미지 정보를 가지고 있음

spatial distribution of intensity level 로 분석됨

→ 이미지 강도에 대한 local variation 과 repeating pattern

- Structural
    - 원시적인 픽셀 정보
    - 벽돌이나 돌 같은거 하나씩 분류 가능
    - 나무잎 보고 분류할 수 있음? 안됨
- Statistical
    - 양적인 정보 → feature vector
    - Gray Scale 이나 intensity 로 계산
    - 덜 직관적이지만, 모든 이미지를 효과적으로 계산 가능
    - input texture 의 분류와 image 를 쪼개는것 둘 다 가능
    - Texture Segmentation
        - boundary 정하고, 한 이미지에서 쪼개는거에 집중
    - Texture Classification
        - 어떤 texture 가 어떤 region 인지 판단하는데 더 집중
        - statistical 한 방법이 집중
    - Texture Measure의 방법
        - Range
            - 이웃들과의 maximum 과 minimum 의 차이
        - Variance
            - 이웃들 지역과의 분산
        - Quantitative Texture Measures
            - LBP (Local Binary Pattern)
                - 나를 기준으로 주변애들이 나를 넘는지 확인 후 넘으면 1 안넘으면 0 해서 수로 나타낸다 00010111 → 23
                - 간단하게 주로 쓰임
                - 이미지를 쪼개 LBP 한 다음 여러 LBP를 합쳐서 계산 할 수 있음
            - GLC (Gray Level Co-occurrence)
                - 쉽게 계산 할 수 있지만, 반복되는 자연정보나 텍스처에 대한 정보가 없음
                
                ![Untitled](1~5%E1%84%8C%E1%85%A1%E1%86%BC%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%B5%20e02da1c335104bdbac1221ceac30e41e/Untitled.png)
                
                - GLCM 의 문제?
                    - 어떻게 d 를 도출할 것이냐?
                    - 여러 d 에 대해서 하고 제일 최대값이 되는 P[i,j] 를 사용
    - Edges and Texture
        - boundary 와 texture 외에도, edge 를 도출했으면 좋겠다
        - edge-enhanced image 를 사용하자
            - edge detector 를 처음으로 사용
            - edge pixel 의 수는 얼마나 지역이 바쁜지 보여줌
            - edge 의 방향도 texture 분석에 도움이 된다
        1. Edgeness per unit area
        2. Histograms of edge magnitude and direction
        - Law 가 texture-energy approach 시작 in a fixed size window
            - texture filter 를 사용해 image filtering
            - texture energy를 계산 by summing absolut value of filtering result
            - features 합치기
        - texture 의 autocorrelation?
            - regular : peek, valley 존재
            - random : peak at [0,0] and 너비가 size of texture
            - coarse[조잡한, 거친?] : function drops off slowly
            - fine[미세] : drops off rapidly
            - fourier 로 표현 가능
- Modeling
    - texture로 modeling

## Shapes 1

Color & Texture 는 global 인거에 비해 shape 는 image attribute 아님

- Region Descriptors
    - Zero-order moment
        - 모멘트가 이미지 분산에 특정화가 된다
        - 이미지 강도의 합
    - Centroid
        - Center of area → first order moment
    - Second Moments
    - Moment Invariants → 돌리거나, scale, mirroring, rotation 가능
    - Contrast second moments
    - Perimeter and Perimeter Length : 매우 중요!
        - 겉에 있으면 1
        - 그 안에 2 등..
        - 4-connected or 8-connected
    - Orientation
        - axis with least second moment
        - orientation of axis of elongation →연장선으로 방향 판단
        - axis of least inertia
    - Hole Counting
        - 1:3개 0:1개 → external
        - 0:3개 1:3개 → internal
        - (e - i) / 4 = hole의 개수
- Boundary
    - 겉에 표면으로 방향을 정해서 코드로 계산
    - 미분값으로도 표현 가능
    - invariant of starting point, size, translation, rotation (?) 강의 확인하자
- Interests Points
    - “interesting” 한 부분을 미리 뽑아내자
    - 0D → single point
    - 1D → lines
    - 2D → corners [interest point!]
    - Local: no segmentation, 잘 안변함
    - Photometric: pixel 에서 제일 뚜렷한 경우
    - Invariant: image transforatmion + illumination 변화에 안변함
    - Zhang
        - harris detector의 interest point extraction 사용
        - cross-correlation 으로 비교
        - 기존 matrix 의 확인

## Shapes 2