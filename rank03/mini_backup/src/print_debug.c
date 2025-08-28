#include "../include/minishell.h"

// 구조체 프린트 함수들

// t_segment 구조체 프린트
void print_segment(t_segment *seg, int indent)
{
    if (!seg)
    {
        printf("%*s[세그먼트] NULL\n", indent, "");
        return;
    }
    
    printf("%*s[세그먼트]\n", indent, "");
    printf("%*s  내용: \"%s\"\n", indent, "", seg->seg ? seg->seg : "(NULL)");
    printf("%*s  인용상태: %d ", indent, "", seg->quoted);
    switch(seg->quoted)
    {
        case UNQUOTED: printf("(인용 없음)\n"); break;
        case SINGLE_QUOTED: printf("(단일 인용)\n"); break;
        case DOUBLE_QUOTED: printf("(이중 인용)\n"); break;
        default: printf("(알 수 없음)\n"); break;
    }
    
    if (seg->next)
        print_segment(seg->next, indent + 2);
}

// t_token 구조체 프린트
void print_token(t_token *token, int index)
{
    if (!token)
    {
        printf("토큰[%d]: NULL\n", index);
        return;
    }
    
    printf("\n토큰[%d]:\n", index);
    printf("  타입: ");
    switch(token->type)
    {
        case TOKEN_WORD: printf("WORD"); break;
        case TOKEN_PIPE: printf("PIPE"); break;
        case TOKEN_REDIR_IN: printf("REDIR_IN (<)"); break;
        case TOKEN_REDIR_OUT: printf("REDIR_OUT (>)"); break;
        case TOKEN_APPEND: printf("APPEND (>>)"); break;
        case TOKEN_HEREDOC: printf("HEREDOC (<<)"); break;
        case TOKEN_ERROR: printf("ERROR"); break;
        default: printf("UNKNOWN(%d)", token->type); break;
    }
    printf("\n");
    
    printf("  값: \"%s\"\n", token->value ? token->value : "(NULL)");
    printf("  인용상태: %d\n", token->quoted);
    printf("  확장됨: %s\n", token->expanded ? "예" : "아니오");
    
    if (token->segments)
    {
        printf("  세그먼트들:\n");
        print_segment(token->segments, 4);
    }
    
    if (token->next)
        print_token(token->next, index + 1);
}

// t_word 구조체 프린트
void print_word(t_word *word)
{
    if (!word)
    {
        printf("[단어] NULL\n");
        return;
    }
    
    printf("[단어 구조체]\n");
    printf("  인용 존재: %s\n", word->has_quote ? "예" : "아니오");
    printf("  인용 상태: %d ", word->quoted_state);
    switch(word->quoted_state)
    {
        case UNQUOTED: printf("(인용 없음)\n"); break;
        case SINGLE_QUOTED: printf("(단일 인용)\n"); break;
        case DOUBLE_QUOTED: printf("(이중 인용)\n"); break;
        default: printf("(알 수 없음)\n"); break;
    }
    
    if (word->segments)
    {
        printf("  세그먼트들:\n");
        print_segment(word->segments, 4);
    }
}

// t_infile 구조체 프린트
void print_infile_array(t_infile **infiles)
{
    if (!infiles)
    {
        printf("  입력파일: NULL\n");
        return;
    }
    
    printf("  입력파일들:\n");
    for (int i = 0; infiles[i] != NULL; i++)
    {
        printf("    [%d] 파일명: \"%s\", 히어독: %s\n", 
               i, 
               infiles[i]->name ? infiles[i]->name : "(NULL)",
               infiles[i]->heredoc ? "예" : "아니오");
    }
}

// t_cmd 구조체 프린트
void print_cmd(t_cmd *cmd, int cmd_index)
{
    if (!cmd)
    {
        printf("명령어[%d]: NULL\n", cmd_index);
        return;
    }
    
    printf("\n명령어[%d]:\n", cmd_index);
    
    // 전체 명령어 출력
    if (cmd->full_cmd)
    {
        printf("  전체명령어: ");
        for (int i = 0; cmd->full_cmd[i] != NULL; i++)
        {
            printf("\"%s\"", cmd->full_cmd[i]);
            if (cmd->full_cmd[i + 1])
                printf(", ");
        }
        printf("\n");
    }
    else
    {
        printf("  전체명령어: NULL\n");
    }
    
    // 입력 파일들
    print_infile_array(cmd->infile);
    
    // 출력 파일들
    if (cmd->outfile)
    {
        printf("  출력파일들:\n");
        for (int i = 0; cmd->outfile[i] != NULL; i++)
        {
            printf("    [%d] \"%s\" (추가모드: %s)\n", 
                   i, 
                   cmd->outfile[i],
                   (cmd->append && cmd->append[i]) ? "예" : "아니오");
        }
    }
    else
    {
        printf("  출력파일: NULL\n");
    }
    
    printf("  확장에서 생성: %s\n", cmd->from_expand ? "예" : "아니오");
}

// t_ast 구조체 프린트 (재귀적)
void print_ast(t_ast *ast, int depth)
{
    if (!ast)
    {
        printf("%*sAST 노드: NULL\n", depth * 2, "");
        return;
    }
    
    printf("%*sAST 노드 (깊이 %d):\n", depth * 2, "", depth);
    printf("%*s  타입: ", depth * 2, "");
    
    switch(ast->type)
    {
        case NODE_COMMAND: printf("COMMAND"); break;
        case NODE_PIPE: printf("PIPE"); break;
        case NODE_REDIRECT_IN: printf("REDIRECT_IN"); break;
        case NODE_REDIRECT_OUT: printf("REDIRECT_OUT"); break;
        case NODE_APPEND: printf("APPEND"); break;
        case NODE_HEREDOC: printf("HEREDOC"); break;
        case NODE_MISSCMD: printf("MISSING_COMMAND"); break;
        default: printf("UNKNOWN(%d)", ast->type); break;
    }
    printf("\n");
    
    if (ast->cmd)
        print_cmd(ast->cmd, depth);
    
    if (ast->left)
    {
        printf("%*s  왼쪽 자식:\n", depth * 2, "");
        print_ast(ast->left, depth + 1);
    }
    
    if (ast->right)
    {
        printf("%*s  오른쪽 자식:\n", depth * 2, "");
        print_ast(ast->right, depth + 1);
    }
}

// t_ms 구조체 프린트 (메인 구조체)
void print_ms(t_ms *ms)
{
    if (!ms)
    {
        printf("minishell 구조체: NULL\n");
        return;
    }
    
    printf("\n================== MINISHELL 상태 ==================\n");
    
    // 기본 정보
    printf("종료 상태: %d\n", ms->exit_status);
    printf("환경변수 개수: %d\n", ms->elements);
    printf("명령어 번호: %d\n", ms->cmd_no);
    printf("명령어 인덱스: %d\n", ms->cmd_index);
    printf("PID 인덱스: %d\n", ms->pid_index);
    printf("히어독 번호: %d\n", ms->heredoc_no);
    printf("입력파일 인덱스: %d\n", ms->infile_index);
    
    // 파일 디스크립터 정보
    printf("입력 FD: %d\n", ms->fd_in);
    printf("출력 FD: %d\n", ms->fd_out);
    printf("이전 FD: %d\n", ms->prev_fd);
    printf("minishell FD: [%d, %d]\n", ms->ms_fd[0], ms->ms_fd[1]);
    printf("표준 복사본: [%d, %d]\n", ms->std_copy[0], ms->std_copy[1]);
    printf("리셋 FD: [%d, %d]\n", ms->reset[0], ms->reset[1]);
    
    // 상태 플래그들
    printf("자식 프로세스: %s\n", ms->child ? "예" : "아니오");
    printf("구문 오류: %s\n", ms->syntax_error ? "예" : "아니오");
    printf("첫 신호: %s\n", ms->sigfirst ? "예" : "아니오");
    printf("히어독 중단: %s\n", ms->heredoc_stop ? "예" : "아니오");
    
    // 경로와 이름들
    printf("명령어 경로: %s\n", ms->cmd_path ? ms->cmd_path : "(NULL)");
    printf("히어독 이름: %s\n", ms->heredoc_name ? ms->heredoc_name : "(NULL)");
    printf("프롬프트: %s\n", ms->prompt ? ms->prompt : "(NULL)");
    
    // 환경변수
    if (ms->envp)
    {
        printf("환경변수들:\n");
        for (int i = 0; ms->envp[i] && i < 10; i++) // 처음 10개만 출력
        {
            printf("  [%d] %s\n", i, ms->envp[i]);
        }
        if (ms->envp[10])
            printf("  ... (더 많은 환경변수 존재)\n");
    }
    
    // 토큰 체인
    if (ms->token)
    {
        printf("\n토큰 체인:\n");
        print_token(ms->token, 0);
    }
    
    // 단어 구조체
    if (ms->word)
    {
        printf("\n현재 단어:\n");
        print_word(ms->word);
    }
    
    // AST 트리
    if (ms->ast)
    {
        printf("\nAST 트리:\n");
        print_ast(ms->ast, 0);
    }
    
    // 현재 명령어
    if (ms->cmd)
    {
        printf("\n현재 명령어:\n");
        print_cmd(ms->cmd, -1);
    }
    
    printf("=====================================================\n\n");
}

// 디버그용 간단한 토큰 체인 출력
void print_token_chain_simple(t_token *tokens)
{
    printf("토큰 체인: ");
    t_token *current = tokens;
    int i = 0;
    
    while (current)
    {
        printf("[%d:", i);
        switch(current->type)
        {
            case TOKEN_WORD: printf("WORD"); break;
            case TOKEN_PIPE: printf("PIPE"); break;
            case TOKEN_REDIR_IN: printf("<"); break;
            case TOKEN_REDIR_OUT: printf(">"); break;
            case TOKEN_APPEND: printf(">>"); break;
            case TOKEN_HEREDOC: printf("<<"); break;
            case TOKEN_ERROR: printf("ERR"); break;
            default: printf("?"); break;
        }
        printf(":\"%s\"]", current->value ? current->value : "");
        
        current = current->next;
        if (current) printf(" -> ");
        i++;
    }
    printf("\n");
}
