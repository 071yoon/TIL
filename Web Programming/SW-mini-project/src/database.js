// let database
const onRequest = indexedDB.open("instagram", 1);

onRequest.onupgradeneeded = () => {
  const database = onRequest.result;
  database.createObjectStore("profile", { autoIncrement: true });
  database.createObjectStore("bio", { autoIncrement: true });
  database.createObjectStore("gallery", { autoIncrement: true });
};

onRequest.onerror = () => {
  alert("Error creating or accessing db");
};

const addEntryToDb = (storeName, entry) => {
  const database = onRequest.result;
  const transaction = database.transaction([storeName], "readwrite");
  const store = transaction.objectStore(storeName);
  store.add(entry);

  // transaction.oncomplete = () => alert(`Entry added to ${storeName}!`)
  transaction.onerror = () => {
    console.log(`error adding Entry to ${storeName}.`);
    console.log(transaction.error);
  };
};

const getEntryFromDb = (storeName, id) => {
  const data = new Promise((resolve, reject) => {
    const database = onRequest.result;
    const transaction = database.transaction([storeName]);
    const store = transaction.objectStore(storeName);
    const request = id ? store.get(id) : store.getAll();
    request.onerror = () => {
      reject(request.error);
      console.log("error getting data from the store");
    };

    request.onsuccess = () => {
      resolve(request.result);
    };
  });

  return Promise.resolve(data);
};

const clearAllEntries = (storeName) => {
  const database = onRequest.result;
  const transaction = database.transaction([storeName], "readwrite");
  const store = transaction.objectStore(storeName);
  store.clear();
};

export { onRequest, addEntryToDb, getEntryFromDb, clearAllEntries };
