#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <cstdlib>

class Finite_State_Machine {
private:
    // 1. Алфавит 
    std::set<std::string> E;
    // 2. Множество состояний
    std::set<std::string> States;
    // 3. Начальное состояние
    std::string Start;
    // 4. Множество конечных состояний
    std::set<std::string> Finish_States;
    // 5. Правила переходов
    std::vector<std::vector<std::string>> Matrix;

public:
    Finite_State_Machine() {
        
    }

    Finite_State_Machine(std::set<std::string> E, std::set<std::string> States, std::string Start, std::set<std::string> Finish_States, std::vector<std::vector<std::string>> Matrix) {
        this->E = E;
        this->States = States;
        this->Start = Start;
        this->Finish_States = Finish_States;
        this->Matrix = Matrix;
    }
    
    void OutMatrix() {
        int n = States.size();
        int m = E.size();
        auto iter = this->States.begin();
        for (int i = 0; i < n; ++i) {
            std::cout << *iter << ": ";
            iter++;
            for (int j = 0; j < m; ++j) {
                std::cout << this->Matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    /*std::set<std::string> Get_E() {
        return this->E;
    }

    void Set_E(std::set<std::string> New_E) {
        this->E = New_E;
    }*/

    Finite_State_Machine Negative_FSM() {  // Отрицание ДКА
        std::set<std::string> temp;
        for (const auto& q : this->States) {
            if (this->Finish_States.find(q) == this->Finish_States.end()) {
                temp.insert(q);
            }
        }
        this->Finish_States = temp;

        return *this;
    }

    std::set<std::string> FinalStates_for_Union(Finite_State_Machine A) { // T = (T1 x Q2) v (Q1 x T2)
        std::set<std::string> result;

        for (const auto& f : this->Finish_States) {
            for (const auto& q : A.States) {
                result.insert(f + q);
            }
        }

        for (const auto& q : this->States) {
            for (const auto& f : A.Finish_States) {
                result.insert(q + f);
            }
        }

        return result;
    }

    Finite_State_Machine Union(Finite_State_Machine A, Finite_State_Machine B) {

        this->Finish_States = A.FinalStates_for_Union(B);

        return *this;
    }

    Finite_State_Machine Direct_Product(Finite_State_Machine F) {
        Finite_State_Machine result;

        // Алфавиты объединяются:
        for (const auto& e: this->E) {
            result.E.insert(e);
        }
        for (const auto& e : F.E) {
            result.E.insert(e);
        }

        // Множество состояний - декартого произведение множеств:
        auto it1 = this->States.begin();
        auto it2 = F.States.begin();
        for (int i = 0; it1 != this->States.end(); ++i, it1++) {
            for (int j = 0; it2 != F.States.end(); ++j, it2++) {
                result.States.insert(*it1 + *it2);
            }
            it2 = F.States.begin();
        }

        // Начальное состояние - пара начальных состояний исходных автоматов:
        result.Start = this->Start + F.Start;

        // Множество конечных состояний - декартого произведение множеств:
        auto it3 = this->Finish_States.begin();
        auto it4 = F.Finish_States.begin();
        for (int i = 0; it3 != this->Finish_States.end(); ++i, it3++) {
            for (int j = 0; it4 != F.Finish_States.end(); ++j, it4++) {
                result.Finish_States.insert(*it3 + *it4);
            }
            it4 = F.Finish_States.begin();
        }

        //Таблица переходов:
        bool flag = false;
        for (const auto& e : this->E) {
            if (F.E.find(e) != F.E.end()) {
                flag = true;
                break;
            }
        }

        if (!flag) { // Если алфавиты совсем разные

        }
        
        else {
            // Если матрицы отличаются количеством столбцов, заполним недостающие столбцы одной матрицы -

            if (this->E.size() < F.E.size()) {
                int m1 = this->E.size();
                int m2 = F.E.size();
                while (m1 < m2) {
                    for (int i = 0; i < this->States.size(); ++i) {
                        this->Matrix[i].push_back("-");
                    }
                    m1 = this->Matrix[0].size();
                }
            }

            else if (F.E.size() < this->E.size()) {
                int m1 = F.E.size();
                int m2 = this->E.size();
                while (m1 < m2) {
                    for (int i = 0; i < this->States.size(); ++i) {
                        F.Matrix[i].push_back("-");
                    }
                    m1 = F.Matrix[0].size();
                }
            }
            else {
                int n = result.States.size();
                int m = result.E.size();
                int koef = F.Matrix.size();
                std::vector<std::vector<std::string>> myVector(n, std::vector<std::string>(m));
                result.Matrix = myVector;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < m; ++j) {
                        if (this->Matrix[i / koef][j] == "-" || F.Matrix[i % koef][j] == "-") {
                            result.Matrix[i][j] = "-";
                        }
                        else {
                            result.Matrix[i][j] = this->Matrix[i / koef][j] + F.Matrix[i % koef][j];
                        }
                    }
                }
            }         
        }

        return result;
    }

    void From_Dot_to_SVG(const char* Out_File, Finite_State_Machine A) { // Создание dot файла по матрице переходов и преобразование его в svg:
        std::ofstream out(Out_File);
        out << "digraph {\n";
        out << " rankdir=\"LR\";\n";
        out << " start [style=filled,color=white, label = \"\"];\n";
        auto iterator = A.States.begin();
        for (int i = 0; i < A.States.size(); ++i) {
            if (A.Finish_States.find(*iterator) != A.Finish_States.end()) {
                out << "  " << *iterator << "[shape=doublecircle]" << ";\n";
            }
            else {
                out << "  " << *iterator << "[shape=circle]" << ";\n";
            }
            iterator++;
        }

        iterator = A.States.begin();
        for (int j = 0; j < A.States.size(); ++j) {

            if (*iterator == A.Start) {
                out << "  " << "start -> " << A.Start << "[label = \"\"]" << ";\n";
            }

            auto it = A.E.begin();
            for (int k = 0; k < A.Matrix[j].size(); ++k) {
                if (A.Matrix[j][k] == "-") {
                    it++;
                    continue;
                }
                out << "  " << *iterator << " -> " << A.Matrix[j][k] << "[label = " << *it << "]" << ";\n";
                it++;
            }
            iterator++;
        }
        out << "}\n";

        // Преобразовываем получившийся дот в svg-картику при помощи dot.exe
        char str[100];
        sprintf_s(str, "start debug\\dot\\dot -Tsvg -O %s %s", Out_File, Out_File);
        system(str);
    }
    
};

int main()
{
    std::set<std::string> Alphabet = { "a", "b" };
    std::set<std::string> Set_of_States = { "q1", "q2" };
    std::string Start_State = "q1";
    std::set<std::string> End_States = { "q2" };
    std::vector<std::vector<std::string>> Rules = { { "q2", "q1" }, { "q2", "q1" } };

    Finite_State_Machine A(Alphabet, Set_of_States, Start_State, End_States, Rules);

    A.From_Dot_to_SVG("First.dot", A);

    std::set<std::string> Set_of_States_B = { "q3", "q4", "q5" };
    std::string Start_State_B = "q3";
    std::set<std::string> End_States_B = { "q5" };
    std::vector<std::vector<std::string>> Rules_B = { { "q4", "q3" }, { "q3", "q4" }, { "q4", "q4" } };

    Finite_State_Machine B(Alphabet, Set_of_States_B, Start_State_B, End_States_B, Rules_B);

    B.From_Dot_to_SVG("Second.dot", B);

    std::cout << "Matrix for A:" << std::endl;
    A.OutMatrix();
    std::cout << std::endl;

    std::cout << "Matrix for B:" << std::endl;
    B.OutMatrix();
    std::cout << std::endl;

    std::ofstream out("Out.md");

    out << "First:  \n";
    out << "![](First.dot.svg)  \n";
    out << "Second:  \n";
    out << "![](Second.dot.svg)  \n";

    
    Finite_State_Machine R = A.Direct_Product(B);  // Пересечение двух ДКА
    R.From_Dot_to_SVG("Intersection.dot", R);
    out << "Intersection:  \n";
    out << "![](Intersection.dot.svg)  \n";
    
    std::cout << "Do you want Union?(Y/N)" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        Finite_State_Machine R = A.Direct_Product(B);     // Объединение двух ДКА
        R = R.Union(A, B);
        R.From_Dot_to_SVG("Union.dot", R);
        out << "Union:  \n";
        out << "![](Union.dot.svg)  \n";
    }

    std::cout << "Do you want Difference?(Y/N)" << std::endl;
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        Finite_State_Machine R = A.Direct_Product(B.Negative_FSM());     // Разность двух ДКА
        R.From_Dot_to_SVG("Difference.dot", R);
        B.From_Dot_to_SVG("NegativeSecond.dot", B);
        out << "SecondNegative:  \n";
        out << "![](NegativeSecond.dot.svg)  \n";
        out << "Difference:  \n";
        out << "![](Difference.dot.svg)  \n";
    }

    std::cout << "Matrix for A x B:" << std::endl;
    R.OutMatrix();

    out.close();
    

    return 0;
}

