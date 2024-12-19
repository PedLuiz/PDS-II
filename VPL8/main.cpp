#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

#define PI M_PI

using namespace std;

class Ponto {
private:
    double x;
    double y;
public:
    Ponto(double x, double y) : x(x), y(y) {}
    Ponto() : x(0), y(0) {}
    
    void setXY (double x, double y) {
        this->x = x;
        this->y = y;
    }

    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }
};
 
/* 
    Atributos:
        Ponto, centro da figura
        
    Metodos
        get set ponto
        desenha 

        calcular area (metodo puro)
 */

class FiguraGeometrica{
protected:
    Ponto centro;

public:
    FiguraGeometrica(double x, double y) {
        centro.setXY(x, y);
    }

    FiguraGeometrica(Ponto c) {
        centro = c;
    }

    void setPonto(double x, double y) {
        centro.setXY(x, y);
    }
    
    Ponto getPonto() {
        return centro;
    }

    virtual void desenha() {
        cout << centro.getX() << " " << centro.getY() << " ";
    }

    virtual float calcularArea() = 0;
};

class Retangulo : public FiguraGeometrica {
private:
    double comprimento;
    double largura;
public:
    Retangulo(Ponto c, double comp, double larg) : FiguraGeometrica(c), comprimento(comp), largura(larg) { }

    void setComprimento(double c) {
        comprimento = c;
    }

    void setLargura(double l) {
        largura = l;
    }

    virtual void desenha () override {
        FiguraGeometrica::desenha();
        cout << "RETANGULO" << endl;
    }

    virtual float calcularArea() override {
        return comprimento * largura;
    }
};

class Triangulo : public FiguraGeometrica {
private:
    double base;
    double altura;

public:
    Triangulo(Ponto c, double b, double h) : FiguraGeometrica(c), base(b), altura(h) { }

    void setBase (double b) {
        base = b;
    }

    void setAltura (double h) {
        altura = h;
    }

    virtual void desenha() override {
        FiguraGeometrica::desenha();
        cout << "TRIANGULO" << endl;
    }

    virtual float calcularArea() override {
        return base * altura / 2;
    }
};

class Circulo : public FiguraGeometrica {
private:
    double raio;

public:
    Circulo(Ponto c, double r) : FiguraGeometrica(c), raio(r) { }

    void setRaio (double r) {
        raio = r;
    }

   virtual void desenha() {
        FiguraGeometrica::desenha();
        cout << "CIRCULO" << endl;
   } 

   virtual float calcularArea() override {
        return PI * pow(raio, 2);
   }
};



int main() {
    vector<FiguraGeometrica*> figuras; 
    char option; cin >> option;
    while (true)  {
        if (option == 'E') break;

        else if (option == 'R') {
            double x, y; cin >> x >> y;
            Ponto centro = Ponto(x, y);
            double comp, larg; cin >> comp >> larg;
            Retangulo* r = new Retangulo(centro, comp, larg);
            figuras.push_back(r);
        }

        else if (option == 'C') { 
            double x, y; cin >> x >> y;
            Ponto centro = Ponto(x, y);
            double raio; cin >> raio;
            Circulo* c = new Circulo(centro, raio);
            figuras.push_back(c);
        }

        else if (option == 'T') {
            double x, y; cin >> x >> y;
            Ponto centro = Ponto(x, y);
            double base, altura; cin >> base >> altura;
            Triangulo* t = new Triangulo(centro, base, altura);
            figuras.push_back(t);
        }

        else if (option == 'D') {
            for (auto& f : figuras) {
                f->desenha();
            }
        }

        else if (option == 'A') {
            float area_total = 0;
            for (auto& f : figuras) {
                area_total += f->calcularArea();
            }
            
            printf("%.2f\n", area_total);
        }
        cin >> option;
    }
    for (auto& i : figuras) {
        delete i;
    }

    return 0;
}