#ifndef UNDOMODEL_H
#define UNDOMODEL_H

#include "slate-global.h"
#include <QAbstractItemModel>
#include <QPointer>

#include <QUndoStack>

class SLATE_EXPORT UndoModel : public QAbstractItemModel {
  Q_OBJECT

public:
  UndoModel(QObject *object = nullptr){};
  explicit UndoModel(QUndoStack *undoStack, QObject *parent = nullptr);
  ~UndoModel();

  // QAbstractItemModel interface
public:
  virtual QModelIndex index(int row, int column,
                            const QModelIndex &parent) const override;
  QModelIndex parent(const QModelIndex &child) const override;
  int rowCount(const QModelIndex &parent) const override;
  int columnCount(const QModelIndex &parent) const override;
  QVariant data(const QModelIndex &index, int role) const override;
  QHash<int, QByteArray> roleNames() const override;

public slots:
  Q_INVOKABLE bool loadModelUndo();

signals:
  void modelListChanged();

public:
  QPointer<QUndoStack> m_undoStack;
  static QList<QString> m_stringContainer;
};

#endif // UNDOMODEL_H
