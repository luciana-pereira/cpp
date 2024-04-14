/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucperei <lucperei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:57:14 by lucperei          #+#    #+#             */
/*   Updated: 2024/02/09 22:27:10 by lucperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Defini as variaveis estáticas como 0 fora do método
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// O construtor recebe um initial_deposit como parâmetro. Ele inicializa os membros da classe e responsável por inicializar uma nova conta com um depósito inicial.
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), // Inicializa o índice da conta com o número total de contas.
		_amount(initial_deposit), // Inicializa o saldo da conta com o valor do depósito inicial.
		_nbDeposits(0), //  Inicializa o número de depósitos feitos nesta conta como zero.
		_nbWithdrawals(0) // Inicializa o número de saques feitos nesta conta como zero.
{
	// O método _displayTimestamp e chamado para exibir o timestamp atual 
	// e imprime uma mensagem indicando a criação da conta, incluindo o 
	// índice da conta, o montante inicial e a palavra "created". 
	// Incrementa o número total de contas. 
	_displayTimestamp();
	std::cout << "index:" << _accountIndex // Imprime o índice da nova conta.
				<< ";amount:" << _amount // Imprime o saldo inicial da nova conta.
				<< ";created" << std::endl; // Imprime uma mensagem indicando que a conta foi criada e uma nova linha para finalizar a mensagem.
	_nbAccounts++; // Incrementa o número total de contas.
	_totalAmount += initial_deposit; // Adiciona o valor do depósito inicial ao total de montantes de todas as contas.
}

//  O destrutor é responsável por imprimir uma mensagem indicando que a conta está sendo fechada, 
// incluindo o índice da conta, o montante final e a palavra "closed". Ele é chamado quando um 
// objeto Account é destruído.
Account::~Account(void)
{
	// Início da definição do destruidor ~Account, responsável por liberar recursos quando um objeto Account é destruído.
	_displayTimestamp();
	std::cout << "index:" << _accountIndex // Imprime o índice da conta.
				<< ";amount:" << _amount // Imprime o saldo final da conta.
				<< ";closed" << std::endl; // Imprime uma mensagem indicando que a conta foi fechada e uma nova linha para finalizar a mensagem.
}

// Métodos estáticos que retornam informações sobre todas as contas

// Número total de contas
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

// Montante total em todas as contas
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

// Número total de depósitos
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

// Número total de retiradas
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// Este método estático exibe informações sobre todas as contas, 
// incluindo o número total de contas, o montante total em todas as contas, 
// o número total de depósitos e o número total de retiradas.
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts  // Imprime o número total de contas.
				<< ";total:" << _totalAmount // Imprime o total de montantes de todas as contas.
				<< ";deposits:" << _totalNbDeposits // Imprime o número total de depósitos em todas as contas.
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl; // Imprime o número total de saques de todas as contas e uma nova linha para finalizar a mensagem.
}

// Os métodos abaixos são responsáveis por fazer depósitos e retiradas em uma conta, respectivamente.
// Recebem o valor do depósito ou retirada como parâmetro e atualizam o montante da conta, o montante 
// total e o número de depósitos ou retiradas. Eles também chamam _displayTimestamp() para imprimir o 
// timestamp atual.
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex // Imprime o índice da conta.
				<< ";p_amount:" << _amount // Imprime o saldo anterior ao depósito.
				<< ";deposit:" << deposit; // Imprime o valor do depósito.
	_amount += deposit; // Adiciona o valor do depósito ao saldo da conta.
	_totalAmount += deposit; // Adiciona o valor do depósito ao total de montantes de todas as contas.
	_nbDeposits++; // Incrementa o número de depósitos feitos nesta conta.
	_totalNbDeposits++; // Incrementa o número total de depósitos em todas as contas.
	std::cout << ";amount:" << _amount // Imprime o novo saldo após o depósito.
				<< ";nb_deposits:" << _nbDeposits // Imprime o número de depósitos feitos nesta conta.
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex // Imprime o índice da conta.
				<< ";p_amount:" << _amount // Imprime o saldo anterior à tentativa de saque.
				<< ";withdrawal:" << withdrawal; // Imprime o valor que está sendo sacado.
	if (_amount >= withdrawal) // Verifica se o saldo disponível na conta é maior ou igual ao valor que está sendo sacado.
	{
		_amount -= withdrawal; // Se o saldo for suficiente, subtrai o valor do saque do saldo da conta.
		_totalAmount -= withdrawal; // Subtrai o valor do saque do saldo total de todas as contas.
		_nbWithdrawals++; // Incrementa o número de saques feitos nesta conta.
		_totalNbWithdrawals++; // Incrementa o número total de saques em todas as contas.
		std::cout << ";amount:" << _amount //  Imprime o novo saldo após o saque.
					<< ";nb_withdrawals:" << _nbWithdrawals // Imprime o número de saques feitos nesta conta.
					<< std::endl;
		return (true); // Retorna verdadeiro para indicar que o saque foi bem-sucedido.
	}
	std::cout << ";refused" << std::endl; // Se o saldo não for suficiente para o saque, imprime ";refused" para indicar que o saque foi recusado.
	return (false); // Retorna falso para indicar que o saque foi recusado.
}

// Retorna o montante atual da conta.
int	Account::checkAmount(void) const
{
	return (_amount);
}

// Exibe o status da conta, incluindo o índice da conta, 
o montante atual, o número de depósitos e o número de retiradas.
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

// Exibe o timestamp atual no formato [AAAAmmdd_HHMMSS].
void	Account::_displayTimestamp(void)
{
	std::time_t	t; // armazenar o tempo.
	std::tm*	now; // Declaração de um ponteiro para uma estrutura tm para armazenar a data e hora local.

	t = std::time(0); //  Obtém o tempo atual em segundos desde a época (00:00:00 UTC em 1 de janeiro de 1970) e armazena-o na variável
	now = std::localtime(&t); Converte o tempo obtido em t para a hora local e armazena na estrutura tm apontada por now
	std::cout << "["
			<< (now->tm_year + 1900) // Adiciona 1900 ao valor do ano retornado por tm_year para obter o ano atual.
			<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1) // Configura a largura do campo de impressão para 2 caracteres e preenche com zeros à esquerda, se necessário. Em seguida, imprime o mês atual (tm_mon é base zero, então adiciona-se 1 para obter o mês real).
			<< std::setw(2) << std::setfill('0') << now->tm_mday // Configura a largura do campo de impressão para 2 caracteres e preenche com zeros à esquerda, se necessário. Em seguida, imprime o dia do mês atual.
			<< "_" // separar a parte da data da parte do tempo.
			<< std::setw(2) << std::setfill('0') << now->tm_hour // Configura a largura do campo de impressão para 2 caracteres e preenche com zeros à esquerda, se necessário. Em seguida, imprime a hora atual.
			<< std::setw(2) << std::setfill('0') << now->tm_min // Configura a largura do campo de impressão para 2 caracteres e preenche com zeros à esquerda, se necessário. Em seguida, imprime o minuto atual.
			<< std::setw(2) << std::setfill('0') << now->tm_sec // Configura a largura do campo de impressão para 2 caracteres e preenche com zeros à esquerda, se necessário. Em seguida, imprime o segundo atual.
			<< "] ";
}

// O Formato acima trara o arquivo com a data e horario do dia, para ser igual ao arquivo comente acima e utilize o de baixo
/*
void Account::_displayTimestamp(void){
	std::cout << "[19920104_091532] ";
};
*/
