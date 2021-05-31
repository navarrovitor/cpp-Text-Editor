#include "LinkedList.h"

int main()
{
  LinkedList linkedList;
  string file = "inteligenciaEmocional.txt", word, oldWord, newWord;
  int run = 0, opt;

  linkedList.loadText(file);

  cout << "Bem vindo ao editor de texto C++!" << endl
       << "Com um arquivo " << file << " de base, você pode:" << endl
       << "- Descobrir o número de vezes que uma palavra aparece no mesmo" << endl
       << "- Mudar as palavras que você desejar" << endl
       << "- Imprimir seu texto no formato de lista ligada no terminal" << endl
       << "- Salvar seu arquivo alterado" << endl
       << endl;

  while (run != 1)
  {
    cout << "---------------------------------------------" << endl
         << "Escolha uma opção:" << endl
         << "1 - Contar número de ocorrências de uma palavra" << endl
         << "2 - Trocar palavra" << endl
         << "3 - Imprimir lista" << endl
         << "4 - Salvar suas alterações no arquivo .txt (sai do programa automaticamente)" << endl
         << "5 - Sair do programa" << endl
         << endl
         << "---------------------------------------------" << endl
         << "Informe sua escolha:" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
      cout << "Qual palavra você quer contar?" << endl;
      cin >> word;
      if (linkedList.countWord(oldWord) == 1)
        cout << "A palavra " << oldWord << " aparece uma vez." << endl;
      else
        cout << "A palavra " << oldWord << " aparece " << linkedList.countWord(oldWord) << " vezes." << endl;
      break;
    case 2:
      cout << "Qual palavra você quer trocar?" << endl;
      cin >> oldWord;
      cout << "Você quer troca-lá por qual palavra?" << endl;
      cin >> newWord;
      if (linkedList.countWord(oldWord) < 1)
      {
        cout << "Essa palavra não aparece no texto." << endl;
        break;
      }
      if (linkedList.countWord(oldWord) == 1)
        cout << "A palavra " << oldWord << " aparece uma vez." << endl;
      else
        cout << "A palavra " << oldWord << " aparece " << linkedList.countWord(oldWord) << " vezes." << endl;
      cout << "Todas as ocorrências da mesma foram trocadas por " << newWord << '.' << endl;
      break;
    case 3:
      cout << "A lista se encontra assim:" << endl;
      linkedList.printList();
      break;
    case 4:
      cout << "Salvando a lista no arquivo " << file << "..." << endl;
      linkedList.saveText(file);
      cout << "Obrigado pela visita! Saindo do programa..." << endl;
      run++;
      break;
    case 5:
      cout << "Obrigado pela visita! Saindo do programa..." << endl;
      run++;
      break;
    default:
      break;
    }
  }
  return 0;
}
