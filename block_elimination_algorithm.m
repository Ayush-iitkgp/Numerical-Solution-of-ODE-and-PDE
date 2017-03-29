function [B,U,d2,d,w,y]=p4(x,n,h)

  %B=zeros(n,n);
  %U=zeros(n,n);
  d=zeros(n,1);
  d1=zeros(2,1);
  y=zeros(n,1);
  temp=zeros(2,2);
  p=zeros(n,1);

  a=[1 0
    0 1];
  b=[-2 81*h^2
    -h^2 -2];
  c=[1 0
    0 1];

  B=cell(n,n);
  U=cell(n,n);
  d=cell(n,1);
  d2=cell(n,1);
  w=cell(n,1);

  %n=5;
  %h=0.1;
  %y(1)=a;
  %y(5)=b;
  i=1;
  B{1,1}=b;
  B{1,2}=c;
  d1(1,1)=81*x(i)^2*h^2;
       d1(2,1)=0;
  d{1,1}=d1; 
  i=n;
  B{i,n-1}=a;
       B{i,n}=b;
       d1(1,1)=81*x(i)^2*h^2;
       d1(2,1)=0;
       d{n,1}=d1;
  for i=2:n-1
    
       B{i,i-1}=a;
       B{i,i}=b;
       B{i,i+1}=c;
       d1(1,1)=81*x(i)^2*h^2;
       d1(2,1)=0;
       d{i,1}=d1;
  end

  L(1,1)=B(1,1);
  U{1,1}=[1 1];U{1,2}=B{1,1}\B{1,2};
  d2{1,1}=B{1,1}\d{1,1};
  for i=2:n-1
    %temp=B{i,i}-B{i,i-1}*U{i-1,i};
    U{i,i+1}=inv(B{i,i}-B{i,i-1}*U{i-1,i})*B{i,i+1};
    U{i,i}=[1 1];
    d2{i,1}=inv(B{i,i}-B{i,i-1}*U{i-1,i})*((d{i,1}-B{i,i-1}*d{i-1,1}));
  end
  U{n,n}=1;
  i=n;
  temp=B{i,i}-B{i,i-1}*U{i-1,i};
  d2{i,1}=inv(B{i,i}-B{i,i-1}*U{i-1,i})*((d{i,1}-B{i,i-1}*d{i-1,1}));
  w{n,1}=d2{n,1};
  y(n,1)=w{n,1}(2,1);
  p(n,1)=w{n,1}(1,1);
  for i=n-1:-1:1
    w{i,1}=d2{i,1}-(U{i,i+1}*w{i+1,1});
    y(i,1)=w{i,1}(2,1);
    p(i,1)=w{i,1}(1,1);
  end
end
