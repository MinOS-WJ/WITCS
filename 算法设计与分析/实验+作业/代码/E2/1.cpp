#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 定义目标函数 f(x) = x^3 - 3x - 1
double f(double x) {
    return x * x * x - 3 * x - 1;
}

// 定义目标函数的导数 f'(x) = 3x^2 - 3
double df(double x) {
    return 3 * x * x - 3;
}

// 二分法求解
// 初始区间 [a, b] = [1, 3]
// 精度要求 eps = 1e-7
double bisectionMethod(double a, double b, double eps) {
    if (f(a) * f(b) >= 0) {
        // 简单错误处理，题目保证有根，此处仅做防御
        return -1; 
    }
    
    double mid = a;
    while ((b - a) / 2.0 > eps) {
        mid = (a + b) / 2.0;
        if (f(mid) == 0) {
            break;
        } else if (f(a) * f(mid) < 0) {
            b = mid;
        } else {
            a = mid;
        }
    }
    return (a + b) / 2.0;
}

// 牛顿迭代法求解
// 初始点 x0 = 4
// 精度要求 eps = 1e-7
double newtonMethod(double x0, double eps) {
    double x1 = x0;
    double x_prev;
    
    do {
        x_prev = x1;
        double fx = f(x_prev);
        double dfx = df(x_prev);
        
        if (fabs(dfx) < 1e-12) {
            // 避免除以零，虽然在此题特定点不会发生
            break;
        }
        
        x1 = x_prev - fx / dfx;
        
    } while (fabs(x1 - x_prev) > eps);
    
    return x1;
}

int main() {
    // 设置输出精度，显示小数点后7位以上以便观察
    cout << fixed << setprecision(9);

    // 1. 二分法求解
    double root_bisect = bisectionMethod(1.0, 3.0, 1e-7);
    
    // 2. 牛顿迭代法求解
    double root_newton = newtonMethod(4.0, 1e-7);
    
    // 3. 计算理论值 2 * cos(20度)
    // C++ trigonometric functions use radians. 20 degrees = 20 * PI / 180
    double pi = acos(-1.0);
    double rad_20 = 20.0 * pi / 180.0;
    double theoretical_val = 2.0 * cos(rad_20);
    
    // 4. 计算误差
    double error_bisect = fabs(root_bisect - theoretical_val);
    double error_newton = fabs(root_newton - theoretical_val);
    
    // 输出结果
    cout << "Equation: x^3 - 3x - 1 = 0" << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "Bisection Method (Initial interval [1, 3]):" << endl;
    cout << "Approximate Root: " << root_bisect << endl;
    
    cout << "Newton's Method (Initial point x0=4):" << endl;
    cout << "Approximate Root: " << root_newton << endl;
    
    cout << "----------------------------------------" << endl;
    cout << "Theoretical Value (2*cos(20deg)): " << theoretical_val << endl;
    
    cout << "Error of Bisection Method: " << error_bisect << endl;
    cout << "Error of Newton's Method:  " << error_newton << endl;

    return 0;
}

/*
 * 算法复杂度分析:
 * 
 * 1. 二分法 (Bisection Method):
 *    - 时间复杂度: O(log((b-a)/eps))。每次迭代区间减半，收敛速度是线性的。
 *      对于本题，初始区间长度为2，精度1e-7，大约需要 log2(2/1e-7) ≈ 24 次迭代。
 *    - 空间复杂度: O(1)，只使用了常数个变量。
 * 
 * 2. 牛顿迭代法 (Newton's Method):
 *    - 时间复杂度: 通常具有二次收敛速度 (Quadratic Convergence)，即 O(log(log(1/eps)))。
 *      这意味着有效数字的位数在每一步大致翻倍。对于本题，通常只需几次迭代即可达到极高精度。
 *      但在最坏情况下（如初始值选择不当或导数接近0），可能不收敛或收敛慢。
 *    - 空间复杂度: O(1)，只使用了常数个变量。
 * 
 * 总结: 牛顿法在接近根时收敛速度远快于二分法，但二分法更加稳健，只要区间内有根且函数连续单调就一定能收敛。
 */