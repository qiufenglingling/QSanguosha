#ifndef CLIENTPLAYER_H
#define CLIENTPLAYER_H

#include "player.h"
#include "clientstruct.h"

class Client;
class QTextDocument;

class ClientPlayer : public Player
{
    Q_OBJECT

public:
    explicit ClientPlayer(Client *client);
    void handCardChange(int delta);
    QList<const Card *> getCards() const;
    void setCards(const QList<int> &card_ids);
    QTextDocument *getMarkDoc() const;
    void changePile(const QString &name, bool add, int card_id);

    virtual int aliveCount() const;
    virtual int getHandcardNum() const;
    virtual void removeCard(const Card *card, Place place);
    virtual void addCard(const Card *card, Place place);
    virtual void addKnownHandCard(const Card *card);
    virtual bool isLastHandCard(const Card *card) const;
    virtual void setMark(const QString &mark, int value);

    QList<int> nullifications() const;

private:
    int handcard_num;
    QList<const Card *> known_cards;
    QTextDocument *mark_doc;

signals:
    void pile_changed(const QString &name);
};

extern ClientPlayer *Self;

#endif // CLIENTPLAYER_H
