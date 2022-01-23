

'''
문제 : 왼쪽부터 계란을 들어서 '한번씩' '다른 계란'을 치는 것

헷갈린 점 :
서로 짝찌었을 때, 한번만 치면 끝이 아니라
들고 있는 계란 제외 다른 계란들을 모두 치는 것 -> 중복해서 칠 수도 있다.

주의해야할 점:
1) 쳤을 때, 들고 있는 계란이 깨진다면 다음 계란으로 넘어갈 것
2) 모든 계란을 다 검사해야 하기 때문에, 계란 idx와 검사 idx(i)가 같다면 다음 검사 실시
3) 검사 계란이 죽어있으면 넘어가기
4) 마지막 계란도 다 검사해봐야 다음 걸로 넘어간다.

결과:
idx가 크기 + 1 로 넘어올 때, 전체 data 검사 시작

참고:
https://jioneprogstdy.tistory.com/134
'''

## 풀이 1
# -------
n = int(input())
data = [list(map(int, input().split())) for _ in range(n)]
res = 0

def trial(ndata, idx):

    global res
    if idx == (n): # 모든 깨진 계란 세기
        ans = 0
        for (rx, ry) in data:
            if rx <= 0:
                ans +=1
        res = max(res, ans)      
        return


    if ndata[idx][0] <= 0: # 공격 계란 죽어있으면 다음 idx
        trial(ndata, idx+1)

    else:
        for i in range(len(ndata)): # 모든 데이터 검사
            nx, ny = ndata[i] # 방어 계란
            x, y = ndata[idx]

            if i == idx == n-1:     # 마지막 경우, 칠 수 있는 계란 다 치고 결과 세기 
                trial(ndata, idx+1)
            if idx == i:    # 공격 계란 == 방어 계란, 넘어가기
                continue
            if nx <= 0:      # 방어 계란 죽어있으면 넘어가기
                continue
            
            attack_egg, defense_egg = x - ny, nx - y
            ndata[idx] = [attack_egg, y] # 계란 죽이기
            ndata[i] = [defense_egg, ny]

            trial(ndata, idx+1)

            ndata[idx] = [x, y] # 원래대로 돌리고 다른 시도 (백트래킹)
            ndata[i] = [nx, ny]

    return

trial(data, 0)
print(res)


# ## 풀이2
# n = int(input())
# data = [list(map(int, input().split())) for _ in range(n)]
# res = 0

# def trial(ndata, idx):

#     global res
#     if idx == (n):
#         ans = 0
#         for (rx, ry) in data:
#             if rx <= 0:
#                 ans +=1
#         res = max(res, ans)      
#         return
    
#     for i in range(len(ndata)): # 모든 데이터 검사
        
#         x, y = ndata[idx]
#         nx, ny = ndata[i] # 방어 계란

#         if x <= 0 or i == idx == (n-1): # 처음 계란이 깨져있거나, 마지막 계란의 경우
#             trial(ndata, idx+1)
#             return
#         if idx == i:    # 공격 계란 == 방어 계란, 넘어가기
#             continue
#         if nx <= 0:      # 방어 계란 죽어있으면 넘어가기
#             continue

#         attack_egg, defense_egg = x - ny, nx - y

#         ndata[idx] = [attack_egg, y] # 죽이기
#         ndata[i] = [defense_egg, ny]

#         trial(ndata, idx+1)

#         ndata[idx] = [x, y] # 원래대로 돌리고 다른 시도
#         ndata[i] = [nx, ny]

#     return

# trial(data, 0)
# print(res)