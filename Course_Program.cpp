// Course_Program.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <list>

using namespace std;


struct Date{
    int day, month, year;
};

class Subject {
public:
    void set_all() {
        set_name();
        set_type();
        set_evaluation();
    }
    void set_name() {
        cout << "Введите название дисциплины: ";
        cin >> _name;
    }
    void set_type() {
        cout << "Введите тип аттестации (экзамен/зачёт): ";
        cin >> exam_type;
    }
    void set_evaluation() {
        if (exam_type == "экзамен") {
            cout << "Введите отметку от 2 до 5: \n";
            cin >> ex_mark;
        }
        else {
            if (exam_type == "зачёт") {
                cout << "Введите отметку о зачёте (зачёт/незачёт): \n";
                cin >> mark;
            }
        }
    }
    void get_name() {
        cout << _name;
    }
    void get_mark() {
        if (ex_mark) { cout << ex_mark; }
        else { cout << mark; };
    }
    int ex_mark = 0;
    string mark;
    string exam_type;
    string _name;
};

class Session: public Subject {
public:
    Subject subject[9];
    int subject_cnt = 0;
    int redline = 0;
    void get_list_subjects() {
        cout << "Список дисциплин: " << endl;
        for (int i = 1; i < 10; i++) {
            cout << i << '.' << ' ';
            subject[i-1].get_name();
            subject[i-1].get_mark();
            cout << endl;
        }
    }
    void add_subject() {
        if (redline < 9) {
            subject[redline].set_all();
            redline++;
        }
        else {
            cout << "Превышено максимальное количество дисциплин в сессии" << endl;
        }
    }
    void edit_name(int number) {
        subject[number].set_name();
    }
    void edit_type(int number){
        subject[number].set_type();
    }
    void edit_mark(int number) {
        subject[number].set_evaluation();
    }
};



class Student: public Session {
public:
    void set_all_student() {
        set_initials();
        set_date_of_birth();
        set_year_of_application();
        set_rec_book();
        set_faculty();
        set_department();
        set_group();
    }
    void Date_birth_out() {
        if (((0 < date_of_birth.day) and (date_of_birth.day < 10)) or ((0 < date_of_birth.month) and (date_of_birth.month < 10))) {
            cout << "Дата рождения: ";
            if (date_of_birth.day < 10) {
                cout << '0' << date_of_birth.day << '.';
            }
            else {
                cout << date_of_birth.day << '.';
            }
            if (date_of_birth.month < 10) {
                cout << '0' << date_of_birth.month << '.';
            }
            else {
                cout << date_of_birth.month << '.';
            }
            cout << date_of_birth.year << endl;
        }
        else {
            cout << "Дата рождения: " << date_of_birth.day << "." << date_of_birth.month << "." << date_of_birth.year << endl;
        }
    }
    void set_initials() {
        cout << "Введите фамилию, имя и отчество студента: ";
        cin >> surname >> name >> patronymic;
    }
    void set_date_of_birth() {
        cout << "Введите дату рождения студента в формате дд мм гггг: ";
        cin >> date_of_birth.day >> date_of_birth.month >> date_of_birth.year;
    }
    void set_year_of_application() {
        cout << "Введите год поступления студента: ";
        cin >> year_of_application;
    }
    void set_rec_book() {
        cout << "Введите номер зачетной книжки: ";
        cin >> num_of_record_book;
    }
    void set_faculty() {
        cout << "Введите институт, в котором обучается студент: ";
        cin.ignore();
        getline(cin, faculty, '\n');
    }
    void set_department() {
        cout << "Введите кафедру института: ";
        getline(cin, department, '\n');
    }
    void set_group() {
        cout << "Введите название группы студента: ";
        cin >> group;
    }
    void print_info() {
        cout << "Студент: " << surname << " " << name << " " << patronymic << endl;
        Date_birth_out();
        cout << "Номер зачётной книжки: " << num_of_record_book << endl;
        cout << "Год поступления: " << year_of_application << endl;
        cout << "Институт: " << faculty << endl;
        cout << "Кафедра: " << department << endl;
        cout << "Группа: " << group << endl;
    }
    void get_session() {
        for (int i = 1; i < 9; i++) {
            cout << "Сессия " << " " << i << endl;
        }
    }
    Session session[8];
    string surname, name, patronymic;
    string faculty, department, group, num_of_record_book;
    Date date_of_birth;
    int year_of_application;
    int session_cnt;
};

struct Node {
    Student st;
    Node* next;
};

Node* head;
int students_count = 0;

void save_to_db() {
    ofstream db_out("database.txt", ios_base::out);
    Node* curr = head;
    db_out << students_count << endl;
    while (curr) {
        db_out << curr->st.surname << endl << curr->st.name << endl << curr->st.patronymic << endl;
        db_out << curr->st.date_of_birth.day << endl << curr->st.date_of_birth.month << endl << curr->st.date_of_birth.year << endl;
        db_out << curr->st.num_of_record_book << endl << curr->st.year_of_application << endl << curr->st.faculty << endl;
        db_out << curr->st.department << endl << curr->st.group << endl;
        db_out << curr->st.session_cnt << endl << curr->st.subject_cnt << endl;
        for (int i = 0; i < curr->st.session_cnt; i++) {
            for (int j = 0; j < curr->st.session[i].subject_cnt; j++) {
                db_out << curr->st.session[i].subject[j]._name << endl << curr->st.session[i].subject[j].exam_type;
                db_out << endl << curr->st.session[i].subject[j].ex_mark << endl << curr->st.session[i].subject[j].mark << endl;
            }
        }
        curr = curr->next;
    }
    db_out.close();
}

void read_db() {
    ifstream db_in("database.txt", ios_base::in);
    int st_count = 0;
    db_in >> students_count;
    for (int i = 0; i < students_count; i++) {
        Student term;
        db_in >> term.surname >> term.name >> term.patronymic >> term.date_of_birth.day >> term.date_of_birth.month >> term.date_of_birth.year >> term.num_of_record_book >> term.year_of_application;
        db_in.ignore();
        getline(db_in, term.faculty, '\n');
        getline(db_in, term.department, '\n');
        db_in >> term.group;
        db_in >> term.session_cnt >> term.subject_cnt;
        for (int i = 0; i < term.session_cnt; i++) {
            for (int j = 0; j < term.session[i].subject_cnt; j++) {
                db_in >> term.session[i].subject[j]._name >> term.session[i].subject[j].exam_type;
                db_in >> term.session[i].subject[j].ex_mark >> term.session[i].subject[j].mark;
            }
        }
        Node* newItem = new Node();
        newItem->st = term;
        if (students_count == 0) {
            newItem->next = NULL;
        }
        else {
            newItem->next = head;
        }
        head = newItem;
        st_count++;
    }
    db_in.close();
    students_count = st_count;
}


Node* get_at(int k) {
    Node* current = new Node();
    current = head;
    for (int i = 0; i < k && current != NULL; i++, current = current->next);
    return current;
}

void add_student_to_list()
{
    Student st;
    st.set_all_student();
    Node* newItem = new Node();
    newItem->st = st;
    if (students_count == 0)
        newItem->next = NULL;
    else
        newItem->next = head;
    head = newItem;
    cout << endl;
    students_count++;

}

void delete_student(int index) {
    if (index >= 0 and index < students_count and students_count>0) {
        Node* current = head;
        struct Node* old;
        if (index == 0) {
            old = head;
            head = current->next;
            delete old;
            students_count--;
        }
        else {
            int i = 0;
            while (current) {
                if (i == index - 1) {
                    old = current->next->next;
                    delete current->next;
                    current->next = old;
                    students_count--;
                    break;
                }
                i++;
                current = current->next;
            }
        }
    }
}

void print_list() {
    Node* current = head;
    cout << endl;
    while (current) {
        current->st.print_info();
        current = current->next;
        cout << endl;
    }
}

void control(){
    int fl = 1;
    while (fl) {
        string a;
        cin >> a;
        system("cls");
        if (a == "add") {
            add_student_to_list();
        }
        if (a == "print") {
            print_list();
        }
        if (a == "find") {
            int f;
            cin >> f;
            get_at(f);
        }
        if (a == "close") {
            fl = 0;
        }
    }
}

int main()
{
    SetConsoleCP(1251); SetConsoleOutputCP(1251);
    read_db();
    control();
    save_to_db();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
