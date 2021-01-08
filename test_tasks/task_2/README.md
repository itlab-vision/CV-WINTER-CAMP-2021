# Задача 2

В данной задаче требуется найти ошибку и исправить ее. Реализация этой задачи содержится в файле `main.cpp`.

### Формулировка:

Пусть существует класс "AtmosphericEngine", у которого есть характеристики:
* Рабочий объем (в литрах) одного цилиндра 
* Количество цилиндров

Также существует класс "TurboEngine" с аналогичными характеристиками.

У обоих классов есть метод get_power, который вычисляет их мощность (в л.с.)

Для обычного (атмосферного) двигателя:

`atmosphereEnginePower = 50 * volume * numCylinders`

Для турбированного двигателя мощность вычисляется по формуле мощности:

`power = atmosphereEnginePower + 30`

Требуется найти ошибки в реализации классов AtmosphericEngine и TurboEngine, а также исправить их таким образом, чтобы суммарная мощность двигателей считалась верно.

### Формат входа: 
1-ая строка - количество двигателей

Для каждой следующей строки: Тип двигателя, объем, количество цилиндров.

```
Пример:
2
atmospheric 1 4
turbo 2 4
```
### Формат выхода: 

Целое число - суммарная мощность двигателей
```
Вывод:
630
```
Объяснение:

`1 * 50 * 4 + (2*50*4+30) = 630`

### Требования:

В поле с ответом требуется написать корректные реализации классов `AtmosphericEngine` и `TurboEngine`.

```
Пример:

class AtmosphericEngine {
public:
    AtmosphericEngine(int volume, int numCylinders)
    : volume_(volume), numCylinders_(numCylinders) {
    }

    int get_power() {
        return 50 * volume_ + numCylinders_;
    }
private:
    int volume_;
    int numCylinders_;
};

class TurboEngine : public AtmosphericEngine {
public:
    TurboEngine(int volume, int numCylinders)
    : AtmosphericEngine(volume, numCylinders) {
    }

    int get_power()  {
        return AtmosphericEngine::get_power() + 30;
    }

};

```

