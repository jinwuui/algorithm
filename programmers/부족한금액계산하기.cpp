using namespace std;

long long solution(int price, int money, int count) {
    long long answer = (count + 1) * price;
    answer *= count / 2.0;
    return answer - money > 0 ? answer - money : 0;
}