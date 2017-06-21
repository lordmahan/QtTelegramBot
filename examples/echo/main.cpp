#include <QCoreApplication>
#include <QDebug>
#include "qttelegrambot.h"

#define TOKEN "YOUR BOT TOKEN"

Telegram::Bot *bot;

void newMessage(Telegram::Message message)
{
    qDebug() << "New message:" << message;

    if (bot && message.type == Telegram::Message::TextType) {
        bot->sendMessage(message.chat.id, message.string);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Started Telegram Bot";
    bot = new Telegram::Bot(TOKEN, true, 500, 4);
    QObject::connect(bot, &Telegram::Bot::message, &newMessage);

    return a.exec();
}
