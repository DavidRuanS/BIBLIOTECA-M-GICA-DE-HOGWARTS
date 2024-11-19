# BIBLIOTECA-MAGICA-DE-HOGWARTS

Este projeto foi desenvolvido em C como parte da avaliação na disciplina de Algoritmos e Estrutura de Dados da Faculdade. O objetivo principal era criar um sistema que envolvesse algum tipo de catálogo, e decidi fazer uma Biblioteca de Hogwarts, unindo minha paixão por Harry Potter e pela leitura.

O sistema apresenta opções organizadas em um menu, permitindo cadastrar livros, buscar por título, listar todos os livros e excluir registros. Os dados são armazenados em um arquivo para garantir a persistência das informações. Este projeto foi uma oportunidade de aplicar conceitos de árvores binárias e manipulação de arquivos em um contexto criativo e divertido.

Modelo do Menu:
![Captura de tela 2024-11-19 161850](https://github.com/user-attachments/assets/59801c6a-badc-417f-9172-2de62dc639a7)

Como funciona cada funcionalidade do projeto:

Cadastrar Livro:
O sistema permite que o usuário insira um novo livro no catálogo informando o título, autor e o ano de lançamento. Esses dados são lidos do terminal e armazenados na estrutura da árvore binária, de forma ordenada pelo título do livro. Isso garante que o catálogo esteja sempre organizado.

![Captura de tela 2024-11-19 162147](https://github.com/user-attachments/assets/42d086a4-5d53-4c5a-94a7-9c1516c54922)

Buscar Livro:
Essa funcionalidade permite que o usuário procure por um livro específico informando seu título. O sistema percorre a árvore binária comparando os títulos até encontrar o livro correspondente, caso ele exista. Quando encontrado, o sistema exibe os detalhes do livro, como o autor e o ano de lançamento. Se o livro não for encontrado, uma mensagem é exibida.

![Captura de tela 2024-11-19 162553](https://github.com/user-attachments/assets/39c51132-b6a9-4411-8e62-3db5d8bbe4ce)


Exibir Todos os Livros:
Aqui, o sistema percorre a árvore binária em ordem alfabética, exibindo todos os livros cadastrados no catálogo. Cada livro é apresentado com seu título, autor e ano de lançamento, facilitando a visualização do acervo completo.

![Captura de tela 2024-11-19 162634](https://github.com/user-attachments/assets/c7b9fba0-c4c8-436c-b5cc-93354b3be310)



Excluir Livro:
Permite remover um livro específico do catálogo, informando apenas o título. O sistema localiza o nó correspondente na árvore binária e o exclui, ajustando os ponteiros para garantir que a estrutura da árvore permaneça intacta. Após a exclusão, o catálogo continua ordenado.

![Captura de tela 2024-11-19 162721](https://github.com/user-attachments/assets/2aff2547-fe9d-4446-9397-a40cca8f1928)




Salvar e Carregar Dados:

Salvar: Ao selecionar a opção "Salvar e Sair", todos os livros cadastrados são gravados em um arquivo chamado biblioteca_hogwarts.txt. Isso permite que as informações sejam armazenadas de forma permanente.
Carregar: Ao iniciar o programa, o sistema verifica se há um arquivo com dados existentes e os carrega para a árvore binária. Assim, os livros cadastrados anteriormente ficam disponíveis, mesmo após o encerramento do programa.    

Essas funcionalidades tornam o sistema prático, organizado e eficiente, permitindo uma interação dinâmica com a biblioteca virtual.


Algoritmos Utilizados

Inserção na Árvore:
Adiciona livros na árvore binária, organizando-os em ordem alfabética com base no título.

Busca na Árvore:
Localiza um livro específico pelo título.

Exibição em Ordem (In-Order Traversal):
Percorre a árvore em ordem crescente para exibir os livros de forma organizada.

Remoção de Nó da Árvore:
Exclui um nó da árvore pelo título, ajustando os ponteiros para manter a estrutura.

Leitura e Escrita de Arquivos:
Salva os livros no arquivo biblioteca_hogwarts.txt e carrega os dados ao reiniciar o programa.
    
   





    
