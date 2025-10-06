
#ifndef __CRGL_TEST_HPP__
#define __CRGL_TEST_HPP__

#include <SDL3/SDL_video.h>
#include <crglContext.hpp>

class crTestContext : public gl::Context 
{
public:
    crTestContext( void );
    ~crTestContext( void );
    virtual bool    Create( const void* in_windowHandle );
    virtual void    Destroy( void );
    virtual bool    MakeCurrent( void );
    virtual bool    Release( void );
    virtual bool    SwapBuffers( void );
    virtual void*   GetFunctionPointer( const char* in_name ) const override;
    virtual void    DebugOuput( const char* in_message ) const;
    
private:
    SDL_Window*     m_renderWindown;
    SDL_GLContext   m_renderContext;
};

class crApp
{    
public:
    crApp( void );
    ~crApp( void );
    void    Run( void );

private:    
    SDL_Window*         m_window;
    gl::Context*        m_ctx;
    gl::Program*        m_program;
    gl::VertexArray*    m_vertexArray;
    gl::Buffer*         m_index;
    gl::Buffer*         m_vertexPos;
    gl::Buffer*         m_vertexCol;
    gl::Image*          m_image;

    void    InitSDL3( void );
    void    FinishSDL3( void );
    void    MainLoop( void );
    void    RenderFrame( void );
    void    InitOpenGL( void );
    void    FinishOpenGL( void );
};

#endif //!__CRGL_TEST_HPP__