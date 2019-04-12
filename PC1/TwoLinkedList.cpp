#include <sstream>
#include "TwoLinkedList.h"

TwoLinkedList::~TwoLinkedList() {
    Node* actual1 = head1;
    Node* actual2 = head2;
    do {
        delete actual1;
        delete actual2;
        actual1=actual1->next;
        actual2=actual2->next;
    } while (actual1 != nullptr && actual2 != nullptr);
}

void TwoLinkedList::push_back1(int value) {
    Node* temporal = new Node(value);
    if (head1 == nullptr) {
        head1 = temporal;
        tail1 = temporal;
    } else {
        tail1->next = temporal;
        tail1 = temporal;
    }
}

void TwoLinkedList::push_back2(int value) {
    Node* temporal = new Node(value);
    if (head2 == nullptr) {
        head2 = temporal;
        tail2 = temporal;
    } else {
        tail2->next = temporal;
        tail2 = temporal;
    }
}

std::string TwoLinkedList::merge(int value) {
    Node* temporal = new Node(value);
    Node* actual1 = head1;
    Node* actual2 = head2;
    do {
        if (actual1->next == actual2->next){
            return "Operacion duplicada";
        } else if (actual1->next != actual2->next) {
            tail1->next = temporal;
            tail1 = temporal;
            tail2->next = temporal;
            tail2 = temporal;
            return "Operacion exitosa";
        }
        actual1=actual1->next;
        actual2=actual2->next;
    } while (actual1 != nullptr && actual2 != nullptr);
}

bool TwoLinkedList::is_merged() {
    Node* actual1 = head1;
    Node* actual2 = head2;
    do {
        if (actual1->next == actual2->next){
            return true;
        } else if (actual1->next != actual2->next) {
            return false;
        }
        actual1=actual1->next;
        actual2=actual2->next;
    } while (actual1 != nullptr && actual2 != nullptr);
}

std::string TwoLinkedList::getlist(int lista) {
    switch (lista) {
        case 1: {
            Node* actual1 = head1;
            std::string valores;
            do {
                valores = valores + std::to_string(actual1->value) + " ";
                actual1 = actual1->next;
            } while (actual1 != nullptr);
            return valores;
        }
        case 2: {
            Node* actual2 = head2;
            std::string valores;
            do {
                valores = valores + std::to_string(actual2->value) + " ";
                actual2 = actual2->next;
            } while (actual2 != nullptr);
            return valores;
        }
        case 0: {
            Node* actual1 = head1;
            Node* actual2 = head2;
            std::string valores;
            do {
                if (actual1->next == actual2->next) {
                    do {
                        valores = valores + std::to_string(actual1->value) + " ";
                        actual1 = actual1->next;
                    } while (actual1 == nullptr);
                }
                actual1 = actual1->next;
                actual2 = actual2->next;
            } while (actual1 != nullptr && actual2 != nullptr);
            return valores;
        }
        default:
            return "Opcion incorrecta";
    }
}

Node* TwoLinkedList::search(int valor) {
    Node* temporal1 = head1;
    Node* temporal2 = head2;
    do {
        if (temporal1->value == valor) {
            return temporal1;
        } else if (temporal2->value == valor) {
            return temporal2;
        }
        temporal1 = temporal1->next;
        temporal2 = temporal2->next;
    } while (temporal1 != nullptr && temporal2 != nullptr);
}

void TwoLinkedList::save(const std::string archivo) {
    std::ofstream texto;
    texto.open(archivo);
    //Primera lista
    Node* actual1 = head1;
    std::string valores1;
    do {
        valores1 = valores1 + std::to_string(actual1->value) + ",";
        actual1 = actual1->next;
    } while (actual1 != nullptr);
    //Segunda lista
    Node* actual2 = head2;
    std::string valores2;
    do {
        valores2 = valores2 + std::to_string(actual2->value) + ",";
        actual2 = actual2->next;
    } while (actual2 != nullptr);
    //Combinados
    Node* actual3 = head1;
    Node* actual4 = head2;
    std::string valores3;
    do {
        if (actual3->next == actual4->next) {
            do {
                valores3 = valores3 + std::to_string(actual3->value) + " ";
                actual3 = actual3->next;
            } while (actual3 == nullptr);
        }
        actual3 = actual3->next;
        actual4 = actual4->next;
    } while (actual3 != nullptr && actual4 != nullptr);
    texto << valores1 << '\n';
    texto << valores2 << '\n';
    texto << valores3 << '\n';
}

void TwoLinkedList::load(std::string archivo) {
    std::ifstream texto(archivo);
    if (texto.is_open()) {
        std::string primeraLista[10];
        std::string segundaLista[10];
        std::string elementosComunes[10];
        std::string fila;
        std::getline(texto, fila);
        while (!texto.eof()) {
            std::getline(texto, fila);
            std::istringstream stringStream(fila);
            int contador = 0;
            while (std::getline(stringStream, fila, ',')) {
                primeraLista[contador] = fila;
                segundaLista[contador] = fila;
                elementosComunes[contador] = fila;
            }
        }
    }
}