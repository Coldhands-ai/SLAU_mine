/* Вариант №3. Группа (Номер группы)
*  Мухаметдинова Снежана
*  Лабораторная работа №1
*  Метод Гаусса с выбором главного элемента по строке
*/

#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

using namespace std;

// Глобальная переменная для определения размера данной матрицы
const int SIZE_MATRIX = 4;

// Перегрузка для умножения матрицы 4х4 на вектор 4х1
vector<double> operator*(const vector<vector<double>>& left_matrix, const vector<double>& right_vec) {
    vector<double> multiply_matrix(SIZE_MATRIX);
    // Умножаем матрицу 4х4 на вектор 4х1 и получаем вектор 4x1
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        double value_multiply = 0.0;
        for (int j = 0; j < SIZE_MATRIX; ++j) {
            value_multiply += left_matrix[i][j] * right_vec[j];
        }
        multiply_matrix[i] = value_multiply;
    }
    return multiply_matrix;
}

// Перегрузка для умножения матриц 4х4
vector<vector<double>> operator*(const vector<vector<double>>& left_matrix, const vector<vector<double>>& right_matrix) {
    vector<vector<double>> multiply_matrix(SIZE_MATRIX, vector<double>(SIZE_MATRIX));
    // Умножаем матрицу 4х4 на матрицу 4х4 и получаем матрицу 4х4
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        for (int j = 0; j < SIZE_MATRIX; ++j) {
            for (int k = 0; k < SIZE_MATRIX; ++k) {
                multiply_matrix[i][j] += left_matrix[i][k] * right_matrix[k][j];
            }
        }
    }
    return multiply_matrix;
}

// Перегрузка для вычитания векторов 4x1
vector<double> operator-(const vector<double>& left_vec, const vector<double>& right_vec) {
    vector<double> subtraction_vec(SIZE_MATRIX);
    // Вычитаем из одного вектора 4х1 другой вектор 4х1
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        subtraction_vec[i] = left_vec[i] - right_vec[i];
    }
    return subtraction_vec;
}

// Класс содержащий информацию о СЛАУ
class Equation {
public:
    void setMatrix(const vector<vector<double>>& new_matrix) { matrix = new_matrix; }
    void setRHSVector(const vector<double>& new_right_vec) { right_vec = new_right_vec; }
    void setSolutionVector(const vector<double>& new_solution) { solution_vec = new_solution; }
    void setCountPermutation() { ++permut; }
    void setValueDeterminant(const double& new_det) { det = new_det; }

    vector<vector<double>> getMatrix() const { return matrix; }
    vector<double> getRHSVector() const { return right_vec; }
    vector<double> getSolutionVector() const { return solution_vec; }
    int getCountPermutation() const { return permut; }
    double getValueDeterminant() const { return det; }

private:
    // Количество перестановок, возникающее при перестановке строк в методе Гаусса
    int permut = 0;
    // Значение определителя
    double det = 0;

    vector<vector<double>> matrix;
    vector<double> right_vec;
    vector<double> solution_vec;
};

// Вывод системы линейных алгебраических уравнений в консоль
void print_equations(const vector<vector<double>>& left_matrix, const vector<double>& right_vec) {
    cout << setprecision(2);
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        for (int j = 0; j < SIZE_MATRIX; ++j) {
            cout << setw(8) << left << fixed << left_matrix[i][j];
        }
        if (!right_vec.empty()) {
            cout << "| " << right_vec[i];
        }
        cout << endl;
    }
    cout << endl;
}

// Вывод вектора в консоль
void print_vector(const vector<double>& output_vec, const string& name_vec) {
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        // Выводим вектор решения СЛАУ
        if (name_vec == "Solution") {
            cout << setprecision(4);
            cout << "x_" << i + 1 << ": " << output_vec[i] << endl;
        }
        // Выводим вектор невязки в другом случае
        else if (name_vec == "Residual") {
            cout << setprecision(15);
            cout << "r_" << i + 1 << ": " << fixed << output_vec[i] << endl;
        }
    }
    cout << endl;
}

//                    ***** 1 Задание *****
// Нахождение решения с помощью метода Гаусса с выбором главного элемента по строке
void method_Gauss(Equation& sles) {
    // Получаем все значения матрицы А, вектора f
    vector<vector<double>> left_matrix = sles.getMatrix();
    vector<double> right_vec = sles.getRHSVector();
    // Создаем вектор решения СЛАУ
    vector<double> solution_equation(SIZE_MATRIX, 0.0);

    for (int i = 0; i < SIZE_MATRIX; ++i) {
        // Инициализация главного элемента. Изначально он находится в матрице А с индексами [0][0]
        double main_element = left_matrix[i][i];
        int index_main_element = i;

        // Поиск индекса главного элемента
        for (int j = i; j < SIZE_MATRIX; ++j) {
            // Если следующий элемент в строке по модулю больше, чем текущий главный элемент, то обновляем его
            if (abs(main_element) < abs(left_matrix[i][j])) {
                main_element = left_matrix[i][j];
                index_main_element = j;
            }
        }
        // Если главный элемент стоит на главной диагонали, то ничего не меняем местами, а сразу делаем итерацию методом Гаусса
        if (index_main_element != i) {
            // Увеличиваем количество перестановок
            sles.setCountPermutation();
            // Меняем строки матрицы А местами
            for (int k = 0; k < SIZE_MATRIX; ++k) {
                swap(left_matrix[k][i], left_matrix[k][index_main_element]);
            }
        }
        
        // Элементарные преобразования. Прямой ход метода Гаусса
        for (int k = i + 1; k < SIZE_MATRIX; ++k) {
            double coeff_multiply = -(left_matrix[k][i] / left_matrix[i][i]);
            right_vec[k] += coeff_multiply * right_vec[i];
            for (int j = 0; j < SIZE_MATRIX; ++j) {
                left_matrix[k][j] += coeff_multiply * left_matrix[i][j];
            }
        }
    }

    // Нахождение решения 'x' системы линейных алгебраических уравнений Ax=f
    for (int i = SIZE_MATRIX - 1; i >= 0; --i) {
        double coeff_multiply = 0.0;
        for (int j = i; j < SIZE_MATRIX; ++j) {
            coeff_multiply += left_matrix[i][j] * solution_equation[j];
            solution_equation[i] = (right_vec[i] - coeff_multiply) / left_matrix[i][i];
        }
    }
    sles.setSolutionVector(solution_equation);

    //                    ***** 3 Задание *****
    // Задание 3. Нахождение определителя матрицы методом Гаусса
    double value_det = left_matrix[0][0];
    // Так как матрица у нас верхнетреугольная, после преобразований.
    // То определитель равен произведению всех диагональных элементов матрицы, с учетом перестановок
    for (int i = 1; i < SIZE_MATRIX; ++i) {
        value_det *= left_matrix[i][i];
    }
    sles.setValueDeterminant(pow(-1, sles.getCountPermutation()) * value_det);
}

//                    ***** 2 Задание *****
// Нахождение вектора невязки
vector<double> find_residual_vector(Equation& sles) {
    // Вектор невязки ищется по формуле r = Ax`- f, где x` - решение СЛАУ Ax=f
    return sles.getMatrix() * sles.getSolutionVector() - sles.getRHSVector();
}

//                    ***** 4 Задание *****
// Нахождение обратной матрицы к данной матрице А
vector<double> find_inverse_matrix(vector<vector<double>> left_matrix, vector<double> right_vec) {
    // Элементарные преобразования над матрицей. Привидение её к верхнему треугольному виду. Прямой ход метода Гаусса
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        for (int k = i + 1; k < SIZE_MATRIX; ++k) {
            double coeff_multiply = -(left_matrix[k][i] / left_matrix[i][i]);
            right_vec[k] += coeff_multiply * right_vec[i];
            for (int j = 0; j < SIZE_MATRIX; ++j) {
                left_matrix[k][j] += coeff_multiply * left_matrix[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        double diagonal_element = left_matrix[i][i];
        for (int j = 0; j < SIZE_MATRIX; ++j) {
            left_matrix[i][j] /= diagonal_element;
        }
        right_vec[i] /= diagonal_element;
    }
    // Обратный ход метода Гаусса. Приведение матрицы А к единичной матрице
    for (int k = SIZE_MATRIX - 1; k > 0; --k) {
        for (int i = k - 1; i >= 0; --i) {
            double temp = left_matrix[i][k];
            for (int j = 0; j < SIZE_MATRIX; ++j) {
                left_matrix[i][j] -= left_matrix[k][j] * temp;
            }
            right_vec[i] -= right_vec[k] * temp;
        }
    }
    return right_vec;
}

int main() {
    // Создается класс, описывающий систему линейных алгебраических уравнений.
    // Содержит информацию о матрице А; векторах x,f; количестве перестановок; определитель
    Equation sles;
    // Инициализируем матрицу А в классе sles
    sles.setMatrix({ { 1.00,  0.47, -0.11,  0.55},
                     { 0.42,  1.00,  0.35,  0.17},
                     {-0.25,  0.67,  1.00,  0.36},
                     { 0.54, -0.32, -0.74,  1.00} });
    // Инициализируем вектор f в классе sles
    sles.setRHSVector({ 1.09,
                        2.87,
                        3.65,
                        4.43 });
    // Создается класс sles_for_inverse_matrix для получения обратной матрицы
    Equation sles_for_inverse_matrix;
    sles_for_inverse_matrix.setMatrix(sles.getMatrix());

    // Выводим исходную СЛАУ в консоль
    cout << "СЛАУ:" << endl;
    print_equations(sles.getMatrix(), sles.getRHSVector());

    // Нахождение решения методом Гаусса
    method_Gauss(sles);
    cout << "Решение СЛАУ:" << endl;
    print_vector(sles.getSolutionVector(), "Solution");

    // Нахождение вектора невязки
    cout << "Невязка:" << endl;
    print_vector(find_residual_vector(sles), "Residual");

    // Нахождения определителя
    cout << setprecision(4) << "Определитель: " << sles.getValueDeterminant() << endl;

    // Нахождение обратной матрицы к матрице А
    vector<vector<double>> inverse_matrix(SIZE_MATRIX, vector<double>(SIZE_MATRIX));
    vector<vector<double>> matrixA = sles_for_inverse_matrix.getMatrix();
    // Вызываем каждый раз метод Гаусса, для разных правых частей
    inverse_matrix[0] = find_inverse_matrix(matrixA, { 1.0, 0.0, 0.0, 0.0 });
    inverse_matrix[1] = find_inverse_matrix(matrixA, { 0.0, 1.0, 0.0, 0.0 });
    inverse_matrix[2] = find_inverse_matrix(matrixA, { 0.0, 0.0, 1.0, 0.0 });
    inverse_matrix[3] = find_inverse_matrix(matrixA, { 0.0, 0.0, 0.0, 1.0 });
    // Транспонирование матрицы
    for (int i = 0; i < SIZE_MATRIX; ++i) {
        for (int j = i; j < SIZE_MATRIX; ++j) {
            if (j != i)
                swap(inverse_matrix[i][j], inverse_matrix[j][i]);
        }
    }
    // Вывод обратной матрицы
    cout << endl << "Обратная матрица: " << endl;
    print_equations(inverse_matrix, sles_for_inverse_matrix.getRHSVector());

    // Проверка правильности нахождения обратной матрицы. Умножаем A*A^-1=E
    vector<vector<double>> unit_matrix = matrixA * inverse_matrix;
    cout << "Проверка обратной матрицы:" << endl;
    print_equations(unit_matrix, sles_for_inverse_matrix.getRHSVector());
    return 0;
}