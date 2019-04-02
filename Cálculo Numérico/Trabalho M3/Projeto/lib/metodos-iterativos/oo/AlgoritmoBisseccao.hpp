#ifndef ALGORITMOBISSECCAO_HPP
#define ALGORITMOBISSECCAO_HPP

#include "../DefinicoesIterativos.hpp"

class AlgoritmoBisseccao
{
    public:
        AlgoritmoBisseccao(const FuncaoMatematica &funcao, double a, double b)
            : _funcao(funcao), _iteracao(0), _a(a), _b(b), _x1(0.0), _erro(1.0)
        {
            this->proximo();
        }

        void proximaIteracao()
        {
            this->redefinirIntervalo();
            this->proximo();
            this->calcularErro();
            this->_iteracao++;
        }

        double valor()
        {
            return _x1;
        }

        double resolverAte(double precisao)
        {
            while (_erro > precisao)
                this->proximaIteracao();
            return this->valor();
        }

        double resolverAte(int numeroIteracoes)
        {
            while (_iteracao < numeroIteracoes)
                this->proximaIteracao();
            return this->valor();
        }

        ~AlgoritmoBisseccao(){}

    private:
        FuncaoMatematica _funcao;
        int _iteracao;
        double _a, _b, _x0, _x1, _erro;

        void proximo()
        {
            _x0 = _x1;
            _x1 = (_a + _b) / 2;
        }

        void calcularErro()
        {
            this->_erro = std::fabs((_x1 - _x0) / _x1);
        }

        void redefinirIntervalo()
        {
            if (this->_funcao(_a) * this->_funcao(_x1) > 0)
                _a = _x1;
            else
                _b = _x1;
        }
};

#endif // ALGORITMOBISSECCAO_HPP
