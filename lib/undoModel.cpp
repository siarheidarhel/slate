#include "undoModel.h"
#include "project.h"
#include <QList>

UndoModel::UndoModel(QUndoStack *undoStack, QObject *parent)
    : QAbstractItemModel(parent), m_undoStack(undoStack) {}

UndoModel::~UndoModel() = default;

QModelIndex UndoModel::index(int row, int column,
                             const QModelIndex &parent) const {
  if (hasIndex(row, column, parent))
    return createIndex(row, column);
  return QModelIndex();
}

QModelIndex UndoModel::parent(const QModelIndex &child) const {
  Q_UNUSED(child);
  return QModelIndex();
}

int UndoModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)

  // return UndoModel::m_stringContainer.count();
  return m_undoStack->count();
}

int UndoModel::columnCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)
  return 1;
}

QVariant UndoModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) {
    return QVariant::fromValue(QString("EMPTY MODEL"));
  }
  const auto roleName = roleNames().value(role, QByteArray{});
  if (roleName.isEmpty()) {
    return QVariant();
  }

  if (roleName == "undoModelData") {

    auto temporaryString = m_undoStack->text(index.row());

    return QVariant::fromValue(temporaryString);
  }

  return QVariant();
}

QHash<int, QByteArray> UndoModel::roleNames() const {
  return {

      {1, "undoModelData"}

  };
}

bool UndoModel::loadModelUndo() {
  beginResetModel();

  endResetModel();
  return true;
}
