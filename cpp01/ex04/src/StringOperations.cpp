#include "../include/StringOperations.hpp"

/*
Este programa tem como objetivo substituir todas as ocorrências de uma substring em uma string original 
por outra substring fornecida

O programa recebe quatro argumentos: a string original (original), a string a ser buscada (search), a 
string a ser usada como substituição (replace) e uma string de resultado (result).
*/
bool	StringOperations::replaceOccurrences(const std::string &original, const std::string &search, 
											const std::string &replace, std::string &result)
{
	std::size_t	index;
	std::size_t	foundIndex;
	bool	found;

	/*
 	A variável index será usada para acompanhar a posição atual na string original durante a busca e 
  	found indica se pelo menos uma substituição foi feita.
 	*/

	index = 0;
	found = false;
	/*
 	Enquanto for possível encontrar a substring de busca na string original (utilizando o método find),
  	o programa entra no loop.
 	*/
	while ((foundIndex = original.find(search, index)) != std::string::npos)
	{
		/*
  		Dentro do loop, quando a substring de busca é encontrada, foundIndex recebe a posição 
    		onde ela foi encontrada na string original.
  		*/

		/*
  		Se a substring de busca for encontrada, found é definido como true, indicando que pelo 
    		menos uma substituição foi feita.
  		*/
		found = true;
		/*
  		A parte da string original entre index e foundIndex (exclusivo) é concatenada à string 
    		result, já que essa parte não será substituída.
  		*/
		result += original.substr(index, foundIndex - index);
		/*
  		Em seguida, a substring de substituição (replace) é concatenada à result.
  		*/
		result += replace;
		/*
  		Atualiza-se o valor de index para a posição imediatamente após a última ocorrência 
    		encontrada da substring de busca na string original.
  		*/
		index = foundIndex + search.length();
	} /* 
 	O loop continua até que não seja possível encontrar mais ocorrências da substring de busca na 
  	string original.

   	 Qualquer parte restante da string original após a última ocorrência da substring de busca é 
     	concatenada à string result.
 	*/
	result += original.substr(index);
	return (found); // Found é retornado, indicando se pelo menos uma substituição foi feita na string original.
}
