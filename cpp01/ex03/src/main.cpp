#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int	main(void)
{
	{
		// Declaração e inicialização de um objeto
		Weapon club = Weapon("crude spiked club");
		// Criação de um objeto HumanA chamado bob, passando o nome "Bob" 
		// e o objeto club como parâmetros para o construtor.
		HumanA bob("Bob", club);
		// Chama o método attack() do objeto bob, que imprime uma mensagem indicando 
		// que Bob ataca com sua arma.
		bob.attack();
		// Alteração do tipo da arma club para "some other type of club".
		club.setType("some other type of club");
		// Chamada novamente do método attack() do objeto bob, que agora imprime uma mensagem 
		// indicando que Bob ataca com a nova arma.
		bob.attack();
	}
	{
		/* 
		Bloco de código semelhante ao anterior, mas com um objeto HumanB chamado jim. 
		Aqui, a arma é atribuída ao objeto jim usando o método setWeapon() e, em seguida, 
		o método attack() é chamado duas vezes, imprimindo mensagens apropriadas.
		*/
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
