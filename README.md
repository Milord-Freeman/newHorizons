Стуктура игры следующая:

main 
-window class
-field class
--wall[] : baseObject
--food[] : baseObject
--food[] : baseObject
-snake class
--body[] : baseObject

window - это стандарный класс для отрисовки окна sfml;
main организует контроль за игрой, в дальнейшем будет переписан под класс game;
field хранит в себе все игровые объекты, 
в т.ч. указатель на змейку (snake), частью которой является её тело (body), 
ячейки с едой (food), стенами (wall), 
в свою очередь эти объекты являются 
наследниками базового класса baseObject
который объявляет виртуальную функцию render() и stepped(snake* whoStepped);
Каждый наследник рисует себя сам по своему, а так же по своему 
ведет себя если на него наступает змейка. snake предоставляет
методы для движения makeNextStep(), роста addBody() и завершения игры die();

Благодаря тому что все игровые объекты являются наследниками базового класса 
добавление или изменение уже существующих производится наследованием и реализацией
двух методов, которые будут описывать как объект будет выглядеть на поле и что он будет делать
если на него наступить. Так возможно добавить несколько видов еды, различные типы стен
или телепорты, например для зацикливания игрового поля. Так же засчет того что змейка - 
это отдельный объект указатель на который помещается в field, есть возможнсть реализовать
мультплеер. А если по аналогии с baseObject создать класс baseGamer, и уже от него наследовать
различные варианты игроков.

Что сделано:
+Создание поля и змейки, инициализация;
+Создание объектов и размещение их на поле случайным образом;
+Движение змейки по полю;

Что требуется доделать:
Таймер который будет обеспечивать игровые тики, обновляя состояния поля;
Реализацию методов stepped();
Обработку условия завершения игры и подсчета очков;
