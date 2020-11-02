/*--------------------------------------------------------------------------*\
 |                                                                          |
 |  Copyright (C) 2017                                                      |
 |                                                                          |
 |         , __                 , __                                        |
 |        /|/  \               /|/  \                                       |
 |         | __/ _   ,_         | __/ _   ,_                                | 
 |         |   \|/  /  |  |   | |   \|/  /  |  |   |                        |
 |         |(__/|__/   |_/ \_/|/|(__/|__/   |_/ \_/|/                       |
 |                           /|                   /|                        |
 |                           \|                   \|                        |
 |                                                                          |
 |      Enrico Bertolazzi                                                   |
 |      Dipartimento di Ingegneria Industriale                              |
 |      Universita` degli Studi di Trento                                   |
 |      Via Sommarive 9, I-38123 Povo, Trento, Italy                        |
 |      email: enrico.bertolazzi@unitn.it                                   |
 |                                                                          |
\*--------------------------------------------------------------------------*/

#ifndef TIC_TOC_HH
#define TIC_TOC_HH

// select computer architecture
#if defined(__APPLE__) && defined(__MACH__)
  // osx architecture
  #define TIC_TOC_OS_OSX 1
#elif defined(__unix__)
  // linux architecture
  #define TIC_TOC_OS_LINUX 1
#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)
  // windows architecture
  #define TIC_TOC_OS_WINDOWS 1
  #ifndef WIN32_LEAN_AND_MEAN
    #define WIN32_LEAN_AND_MEAN
  #endif
  #include <windows.h>
  // workaround for windows that may define min and max as macros
  #ifdef min
    #undef min
  #endif
  #ifdef max
    #undef max
  #endif
#else
  #error "unsupported OS!"
#endif

// check if compiler is C++11
#if (defined(_MSC_VER) &&  _MSC_VER >= 1800) || \
    (defined(__cplusplus) && __cplusplus > 199711L)
  #ifndef TIC_TOC_DO_NOT_USE_CXX11
    #define TIC_TOC_USE_CXX11
  #endif
#else
  // "LapackWrapper libray compiled without c++11 support, cannot use thread"
  // not C++11 compiler
  #ifndef nullptr
    #define nullptr NULL
  #endif
#endif

#define TIC_TOC_PURE_VIRTUAL = 0
#if defined(TIC_TOC_USE_CXX11) && !defined(TIC_TOC_OS_WINDOWS)
  #define TIC_TOC_OVERRIDE  override
  #define TIC_TOC_CONSTEXPR constexpr
  #ifdef __clang__
    #pragma clang diagnostic ignored "-Wc++98-compat"
  #endif
#else
  #define TIC_TOC_OVERRIDE
  #define TIC_TOC_CONSTEXPR
#endif

#if defined(TIC_TOC_OS_WINDOWS) && defined(_MSC_VER)
  // automatically include windows libs in visual studio
  #pragma comment(lib, "shell32.lib")
  #pragma comment(lib, "kernel32.lib")
  #pragma comment(lib, "advapi32.lib")
  #pragma comment(lib, "ws2_32.lib")
  #pragma comment(lib, "IPHLPAPI.lib")
  #pragma comment(lib, "Shlwapi.lib")
  #pragma comment(lib, "iphlpapi.lib")
#endif

#ifdef TIC_TOC_OS_WINDOWS
  #include <windows.h>
  class TicToc {

    typedef double real_type;
    LARGE_INTEGER frequency; // ticks per second
    LARGE_INTEGER t1, t2;    // ticks
    real_type elapsed_time;

    TicToc( TicToc const & );
    TicToc const & operator = ( TicToc const & ) const;

  public:

    TicToc()
    : elapsed_time(0)
    { QueryPerformanceFrequency(&frequency); tic(); }

    ~TicToc() {}

    void
    tic()
    { QueryPerformanceCounter(&t1); }

    void
    toc() {
      QueryPerformanceCounter(&t2);
      elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;;
    }

    real_type
    elapsed_s() const
    { return 1e-3*elapsed_time; }

    real_type
    elapsed_ms() const
    { return elapsed_time; }

  };

  inline
  void
  sleep_for_seconds( unsigned s )
  { Sleep(DWORD(s)*1000); }

  inline
  void
  sleep_for_milliseconds( unsigned ms )
  { Sleep(DWORD(ms)); }

#else

  #ifdef TIC_TOC_USE_CXX11

    #include <chrono>
    #include <thread>

    class TicToc {

      typedef double real_type;
      #ifdef TIC_TOC_USE_HRC
      typedef std::chrono::high_resolution_clock clock;
      #else
      typedef std::chrono::steady_clock clock;
      #endif

      using elapsed_resolution = std::chrono::microseconds;

      clock::time_point start_time;
      clock::time_point stop_time;

      elapsed_resolution elapsed_time;

      TicToc( TicToc const & );
      TicToc const & operator = ( TicToc const & ) const;

    public:

      TicToc()
      : elapsed_time(0)
      { tic(); }

      ~TicToc() {}

      void
      tic()
      { start_time = clock::now(); }

      void
      toc() {
        stop_time    = clock::now();
        elapsed_time = std::chrono::duration_cast<elapsed_resolution>(stop_time - start_time);
      }

      real_type
      elapsed_s() const
      { return 1e-6*elapsed_time.count(); }

      real_type
      elapsed_ms() const
      { return 1e-3*elapsed_time.count(); }

      real_type
      elapsed_us() const
      { return elapsed_time.count(); }
    };

    inline
    void
    sleep_for_seconds( unsigned s )
    { std::this_thread::sleep_for(std::chrono::seconds(s)); }

    inline
    void
    sleep_for_milliseconds( unsigned ms )
    { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }

  #else

    #include <sys/time.h>
    #include <unistd.h>

    inline
    bool
    getTime( long & sec, long & usec ) {
      struct timeval now;
      bool ok = gettimeofday(&now, nullptr) == 0;
      if ( ok ) {
        sec  = now . tv_sec;
        usec = now . tv_usec;
      } else {
        sec = usec = 0;
      }
      return ok;
    }

    class TicToc {

      typedef double real_type;
      long sec, usec;
      real_type elapsed_time;

      TicToc( TicToc const & );
      TicToc const & operator = ( TicToc const & ) const;

    public:

      TicToc()
      : elapsed_time(0)
      { tic(); }

      ~TicToc() {}

      void
      tic()
      { getTime( sec, usec ); }

      void
      toc() {
        long new_sec, new_usec;
        getTime( new_sec, new_usec );
        elapsed_time = 1e3*(new_sec-sec)+1e-3*(new_usec-usec);
      }

      real_type
      elapsed_s() const
      { return 1e-3*elapsed_time; }

      real_type
      elapsed_ms() const
      { return elapsed_time; }
    };

    inline
    void
    sleep_for_seconds( unsigned s ) {
      useconds_t us = s; us *= 1000000;
      usleep(us);
    }

    inline
    void
    sleep_for_milliseconds( unsigned ms ) {
      useconds_t us = ms; us *= 1000;
      usleep(us);
    }

  #endif

#endif

#endif
