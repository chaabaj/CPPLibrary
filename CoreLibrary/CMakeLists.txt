cmake_minimum_required(VERSION 2.6)

set (SRCS
AThread.cpp
Chunk.cpp
CondVar.cpp
FixedAllocator.cpp
LibraryLoader.cpp
Mutex.cpp
ScopedLock.cpp
SmallObjectAllocator.cpp
TypeInfo.cpp
FactoryPlateform.cpp
Timer.cpp
)

set (HEADERS
../include/CoreLibrary/Garbage/enable_if.hpp
../include/CoreLibrary/String/RawBuffer.hpp
../include/CoreLibrary/String/StringConverter.hpp
../include/CoreLibrary/Container/Policies/RejectInvalidIndex.hpp
../include/CoreLibrary/Container/Policies/NoCheck.hpp
../include/CoreLibrary/Container/Container.hpp
../include/CoreLibrary/Container/SetContainer.hpp
../include/CoreLibrary/Exceptions/IOException.hpp
../include/CoreLibrary/Utils/Stringify.hpp
../include/CoreLibrary/Utils/SearchMostDerivated.hpp
../include/CoreLibrary/Utils/LibraryLoader.hpp
../include/CoreLibrary/Utils/SafeCast.hpp
../include/CoreLibrary/Utils/StaticAssert.hpp
../include/CoreLibrary/Reflector/MethodCaller.hpp
../include/CoreLibrary/SmartPointer/AutoPtr.hpp
../include/CoreLibrary/SmartPointer/SmartPointer.hpp
../include/CoreLibrary/SmartPointer/WeakPtr.hpp
../include/CoreLibrary/SmartPointer/SharedPtr.hpp
../include/CoreLibrary/SmartPointer/LockingProxy.hpp
../include/CoreLibrary/SmartPointer/IntrusivePtr.hpp
../include/CoreLibrary/SmartPointer/UniquePtr.hpp
../include/CoreLibrary/CondVar/CondVar.hpp
../include/CoreLibrary/CondVar/CondVarException.hpp
../include/CoreLibrary/CondVar/ICondVarPlateform.h
../include/CoreLibrary/Policies/ThreadingModel/SingleThreaded.hpp
../include/CoreLibrary/Policies/ThreadingModel/MultiThreaded.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/RejectNullStrict.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/AssertCheckStrict.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/RejectNull.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/AssertCheck.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/NoCheck.hpp
../include/CoreLibrary/Policies/SmartPointer/Checking/RejectNullStatic.hpp
../include/CoreLibrary/Policies/SmartPointer/Storage/LockedStorage.hpp
../include/CoreLibrary/Policies/SmartPointer/Storage/DefaultStorage.hpp
../include/CoreLibrary/Policies/SmartPointer/Storage/ArrayStorage.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/RefCountedMT.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/RefCounted.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/DestructiveCopy.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/IntrusiveCounter.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/Nothing.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/NoCopy.hpp
../include/CoreLibrary/Policies/SmartPointer/Ownership/IntrusiveCounterMT.hpp
../include/CoreLibrary/Policies/Factory/DefaultError.hpp
../include/CoreLibrary/Policies/Singleton/PhoenixSingleton.hpp
../include/CoreLibrary/Policies/Singleton/InfiniteLifeTime.hpp
../include/CoreLibrary/Policies/Singleton/MallocCreator.hpp
../include/CoreLibrary/Policies/Singleton/DefaultLifeTime.hpp
../include/CoreLibrary/Policies/Singleton/SingleThreaded.hpp
../include/CoreLibrary/Policies/Singleton/NewCreator.hpp
../include/CoreLibrary/Functor/FunctorHandler.hpp
../include/CoreLibrary/Functor/FunctorImpl.hpp
../include/CoreLibrary/Functor/MemberFunctionHandler.hpp
../include/CoreLibrary/Functor/FunctorBind.hpp
../include/CoreLibrary/Functor/FunctorChain.hpp
../include/CoreLibrary/Functor/Functor.hpp
../include/CoreLibrary/Allocator/SmallObjectAllocator.hh
../include/CoreLibrary/Allocator/FixedAllocator.hh
../include/CoreLibrary/Allocator/SmallObject.hpp
../include/CoreLibrary/Allocator/Chunk.hh
../include/CoreLibrary/Atomic/Atomic.h
../include/CoreLibrary/Mutex/Mutex.h
../include/CoreLibrary/Mutex/ScopedLock.h
../include/CoreLibrary/Mutex/IMutexPlateform.h
../include/CoreLibrary/Mutex/MutexException.h
../include/CoreLibrary/ThreadPool/SafeQueue.hpp
../include/CoreLibrary/Thread/AThread.hpp
../include/CoreLibrary/Thread/ThreadFunctor.hpp
../include/CoreLibrary/Thread/AThreadException.hpp
../include/CoreLibrary/Thread/IThreadPlateform.h
../include/CoreLibrary/Pattern/Registry.hpp
../include/CoreLibrary/Pattern/Factory.hpp
../include/CoreLibrary/Pattern/CloneFactory.hpp
../include/CoreLibrary/Pattern/SingletonHolder.hpp
../include/CoreLibrary/Type/GenScatterHierarchy.hpp
../include/CoreLibrary/Type/System.hpp
../include/CoreLibrary/Type/Type2Type.hpp
../include/CoreLibrary/Type/Tuple.hpp
../include/CoreLibrary/Type/Value2Type.hpp
../include/CoreLibrary/Type/SelectType.hpp
../include/CoreLibrary/Type/Conversion.hpp
../include/CoreLibrary/Type/TypeInfo.hpp
../include/CoreLibrary/Type/Int2Type.hpp
../include/CoreLibrary/Type/TypeList.hpp
../include/CoreLibrary/Type/TypeTraits.hpp
../include/CoreLibrary/Type/NullType.hpp
../include/CoreLibrary/FactoryPlateform/FactoryPlateform.h
../include/CoreLibrary/DllExport.h
../include/CoreLibrary/Utils/Timer.hh
)

if (UNIX)
  set (SRCS_PLATEFORM
  linux/MutexLinux.cpp
  linux/CondVarLinux.cpp
  linux/ThreadLinux.cpp
  )

  set (HEADERS_PLATEFORM
  ../include/CoreLibrary/Mutex/linux/MutexLinux.h
  ../include/CoreLibrary/CondVar/linux/CondVarLinux.h
  ../include/CoreLibrary/Thread/linux/ThreadLinux.h
  )
   
endif()

if (WIN32)
  set (SRCS_PLATEFORM
  windows/MutexWindows.cpp
  windows/CondVarWindows.cpp
  windows/ThreadWindows.cpp
  )

  set (HEADERS_PLATEFORM
  ../include/CoreLibrary/Mutex/windows/MutexWindows.h
  ../include/CoreLibrary/CondVar/windows/CondVarWindows.h
  ../include/CoreLibrary/Thread/windows/ThreadWindows.h
  )
endif()

find_package (Threads)

add_library(CoreLibrary SHARED ${SRCS} ${SRCS_PLATEFORM} ${HEADERS} ${HEADERS_PLATEFORM})

TARGET_LINK_LIBRARIES(CoreLibrary ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})