# include  <iostream> 

// Для автоматического сохранения в UTF-8 всех новых файлов, содержащих символы, 
// отличные от набора ASCII, необходимо включить опцию
// - Tools > Options > Environment > Documents > Save documents as Unicode when data cannot be saved in codepage

int  main() {
   
    setlocale(LC_ALL, "Russian");
    system("chcp 1251"); // настраиваем кодировку консоли
   
    std::cout << "Компьютер: Привет, мир!" << std::endl;
    std::cout << "Человек, как тебя зовут?" << std::endl;

    std::string name;
    std::cin >> name;
    std::cout << "Привет, " << name << "!";
    
    return 0;
}